#include"stdafx.h"
#include"FileDetail.h"
#include"db_connect.h"
#include <string>
using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Security::Cryptography;
using namespace System::Runtime::InteropServices;



int readDir(String^ name)
{
	int count = 0;
	array<String^>^ copies = gcnew array<String^>(50);
	try
	{
		String^ query = "Insert into fms.folder_general values('";
		
		// Create a DirectoryInfo object representing the specified directory.
		DirectoryInfo^ dir = gcnew DirectoryInfo(name);
		
		// Get the FileInfo objects for every file in the directory. 
		array<FileInfo^>^files = dir->GetFiles();
		array<DirectoryInfo^>^directories = dir->GetDirectories();

		// Initialize a SHA256 hash object.
		SHA256 ^ mySHA256 = SHA256Managed::Create();
		array<Byte>^hashValue;

		std::string dName = (char*)(void*)Marshal::StringToHGlobalAnsi(dir->Name);
		array<Byte>^ data = gcnew array<Byte>(dName.size());
		System::Runtime::InteropServices::Marshal::Copy(IntPtr(&dName[0]), data, 0, dName.size());
		hashValue = mySHA256->ComputeHash(data);
		
		query+=dir->GetHashCode()+"','"+dir->Name+"','";
		query+= (dir->FullName)->Replace("\\","\\\\")+"',";
		query+= directories->LongLength+",";
		query+= files->LongLength+",'";

		query += dir->CreationTime.Year.ToString() + "-" + dir->CreationTime.Month.ToString() + "-" + dir->CreationTime.Day.ToString()+"','";
		
		query += dir->LastAccessTime.Year.ToString() + "-" + dir->LastAccessTime.Month.ToString() + "-" + dir->LastAccessTime.Day.ToString() + "','";

		query += "akhil','akhil-pc',0,'" + StringfromByteArray(hashValue)+"'); ";

		MySqlConnection^ ins = Connect();
		EditTable(query, ins);
		ins->Close();

		
		// Compute and print the hash values for each file in directory.
		System::Collections::IEnumerator^ myEnum = files->GetEnumerator();
		while (myEnum->MoveNext())
		{
			
			FileInfo^ fInfo = safe_cast<FileInfo^>(myEnum->Current);

			
			if (getInfo(fInfo->FullName) == -1)
			{
				copies[count] = fInfo->FullName;
				count++;
			}
			
			
		}
		
		myEnum = directories->GetEnumerator();
		while (myEnum->MoveNext())
		{
			
			DirectoryInfo^ dInfo = safe_cast<DirectoryInfo^>(myEnum->Current);
			readDir(dInfo->FullName);
			
		}
		
	}
	catch (DirectoryNotFoundException^)
	{
		Console::WriteLine("Error: The directory specified could not be found.");
	}
	catch (IOException^)
	{
		Console::WriteLine("Error: A file in the directory could not be accessed.");
	}
	return count;

}