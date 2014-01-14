#include "stdafx.h"

#include <iostream>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <windows.h>
#include <objidl.h>
#include "db_connect.h"
#include <gdiplus.h>
#include "FileDetail.h"
#include "Tools.h"
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")
using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Security::Cryptography;
using namespace System::Runtime::InteropServices;

String^ StringfromByteArray(array<Byte>^array)
{
	int i;
	String^ ret;
	for (i = 0; i < array->Length; i++)
	{
		ret += String::Format("{0:X2}", array[i]);


	}
	return ret;
}

String^ calculateHash(String^ filename)
{
	SHA256 ^ mySHA256 = SHA256Managed::Create();
	array<Byte>^hashValue;

	FileInfo^ fInfo = gcnew FileInfo(filename);

	// Create a fileStream for the file.
	FileStream^ fileStream = fInfo->Open(FileMode::Open);

	// Compute the hash of the fileStream.
	hashValue = mySHA256->ComputeHash(fileStream);
	fileStream->Close();
	return StringfromByteArray(hashValue);

}



//fetches attributes of the given file.
String^ getAttributes(FileInfo^ fi)
{
	FileAttributes fa = File::GetAttributes(fi->ToString());
	String^ ret = "";

	if ((fa & FileAttributes::Normal) == FileAttributes::Normal)
		ret = "<normal>";
	else
	{
		if ((fa & FileAttributes::Archive) == FileAttributes::Archive)
			ret += "a";
		if ((fa & FileAttributes::Hidden) == FileAttributes::Hidden)
			ret += "h";
		if ((fa & FileAttributes::System) == FileAttributes::System)
			ret += "s";
		if ((fa & FileAttributes::ReadOnly) == FileAttributes::ReadOnly)
			ret += "r";
		if ((fa & FileAttributes::Compressed) == FileAttributes::Compressed)
			ret += "z";
		if ((fa & FileAttributes::Encrypted) == FileAttributes::Encrypted)
			ret += "e";
	}

	return ret;

}

//fetches details of document files
void getDocumentDetails(FileInfo^ fi, string ext)
{
	const char* path = (const char*)(void*)Marshal::StringToHGlobalAnsi(fi->ToString());
	unsigned int number_of_lines = 0, word_count = 0, char_count = 0;
	if (ext.compare(".pdf") == 0)
	{

	}
	else
	{
		FILE *infile = fopen(path, "r");
		int ch;

		while (EOF != (ch = getc(infile)))
		{
			if (' ' == ch)
				++word_count;
			if ('\n' == ch)
			{
				++number_of_lines;
				++word_count;
			}
			++char_count;
		}
		fseek(infile, -1, SEEK_END);
		if (getc(infile) != '\n')
		{
			number_of_lines++;
			word_count++;
		}
		//	//	printf("Line Count:%u\nWord count:%u\nCharacter count:%u\n", number_of_lines, word_count, char_count);
		String^ dquery = "insert into fms.file_image(";
		dquery += number_of_lines + "," + word_count + "," + char_count + ");";
	}
}

//fetches details of image files
void getImageDetails(FileInfo^ fi)
{
	const char* path = (const char*)(void*)Marshal::StringToHGlobalAnsi(fi->ToString());

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	Image* image = new Image(L"c:\\users\\akhil\\desktop\\as.jpg");
	String^ iquery = "insert into fms.file_image(";

	UINT imageHeight = image->GetHeight();
	iquery += imageHeight + ",";

	UINT imageWidth = image->GetWidth();
	iquery += imageWidth + ",";

	switch (image->GetPixelFormat())
	{
	case PixelFormat1bppIndexed: iquery += "'PixelFormat1bppIndexed' "; break;
	case PixelFormat4bppIndexed: iquery += "'PixelFormat4bppIndexed' "; break;
	case PixelFormat8bppIndexed: iquery += "'PixelFormat8bppIndexed' "; break;
	case PixelFormat16bppARGB1555: iquery += "'PixelFormat16bppARGB1555' "; break;
	case PixelFormat16bppGrayScale: iquery += "'PixelFormat16bppGrayScale' "; break;
	case PixelFormat16bppRGB555: iquery += "'PixelFormat16bppRGB555' "; break;
	case PixelFormat16bppRGB565: iquery += "'PixelFormat16bppRGB565' "; break;
	case PixelFormat24bppRGB: iquery += "'PixelFormat24bppRGB' "; break;
	case PixelFormat32bppARGB: iquery += "'PixelFormat32bppARGB' "; break;
	case PixelFormat32bppPARGB: iquery += "'PixelFormat32bppPARGB' "; break;
	case PixelFormat32bppRGB: iquery += "'PixelFormat32bppRGB' "; break;
	case PixelFormat48bppRGB: iquery += "'PixelFormat48bppRGB' "; break;
	case PixelFormat64bppARGB: iquery += "'PixelFormat64bppARGB' "; break;
	case PixelFormat64bppPARGB: iquery += "'PixelFormat64bppPARGB' "; break;

	}

	iquery += ","+image->GetHorizontalResolution() + ",";
	iquery += image->GetVerticalResolution();
	iquery += ");";


	delete image;
	GdiplusShutdown(gdiplusToken);
}

//gets general information of the given file
int getInfo(String^ name)
{
	int version = 1;
	MySqlConnection^ conn = Connect();
	FileInfo^ fi = gcnew FileInfo(name);
	String^ sha2 = calculateHash(name);
	MySqlDataReader^ scan = QueryTable("Select version from fms.file_general where content_hash='" + sha2 + "' and  owner_id='" + GetCurrentUser() + "';", conn);
	if (scan->Read())
		return -1;
	scan->Close();
	scan = QueryTable("Select version from fms.file_general where content_hash='" + sha2 + "';", conn);
	if (scan->Read())
		version = scan->GetInt16(0)+1;
	scan->Close();
	String^ fquery = "insert into fms.file_general values('";
	fquery += fi->GetHashCode() + "','";

	fquery += (fi->FullName)->Replace("\\", "\\\\") + "','";
	fquery += fi->Directory + "',";

	fquery += (fi->Length / (1024.0* 1024.0)) + ",'";

	string ext = (char*)(void*)Marshal::StringToHGlobalAnsi(fi->Extension);
	fquery += fi->Extension + "','";

	fquery += fi->CreationTime.Year.ToString() + "-";
	fquery += fi->CreationTime.Month.ToString() + "-";
	fquery += fi->CreationTime.Day.ToString() + "','";


	fquery += fi->LastAccessTime.Year.ToString() + "-";
	fquery += fi->LastAccessTime.Month.ToString() + "-";
	fquery += fi->LastAccessTime.Day.ToString() + "','";

	fquery += "akhil-pc','"+GetCurrentUser()+"',null,+"+version+"," + "'" + sha2 + "',0,'" + getAttributes(fi) + "'); ";
	

	EditTable(fquery, conn);
	conn->Close();
	/*
	if (ext.compare(".txt") == 0 || ext.compare(".pdf") == 0)
	getDocumentDetails(fi, ext);
	else if (ext.compare(".jpg") == 0 || ext.compare(".bmp") == 0)
	getImageDetails(fi);
	*/
	return 1;

}