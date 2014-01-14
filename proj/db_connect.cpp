// ConsoleApplication2.cpp : main project file

#include "stdafx.h"
#include "db_connect.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Runtime::InteropServices;


MySqlConnection^ Connect()
{
	String^ cn = L"datasource=localhost;port=3306;username=root;password=a123";
	MySqlConnection^ db = gcnew MySqlConnection(cn);
	try{
		Console::WriteLine(L"Hello");
		db->Open();
		Console::WriteLine(L"Connection Successful");
		

	}
	catch (Exception^ex)
	{
		Console::WriteLine(ex->Message);
	}
	
	return db;
}

int EditTable(String^ statement, MySqlConnection^ conn)
{
	MySqlCommand^ cmd = gcnew MySqlCommand(statement, conn);
	try{
		if (cmd->ExecuteNonQuery() != -1)
			return 1;
		else
			return 0;
	}
	catch (Exception^ex)
	{
		return -1;
		Console::WriteLine(ex->Message);
	}

	
}

MySqlDataReader^ QueryTable(String^ statement, MySqlConnection^ conn)
{
	
	
	MySqlCommand^ cmd = gcnew MySqlCommand(statement, conn);
	MySqlDataReader^ reader;
	try{
		reader = cmd->ExecuteReader();
		return reader;
		
	}
	catch (Exception^ex)
	{
		Console::WriteLine(ex->Message);
		return nullptr;
	}
	
	
}

int testmain()
{
	MySqlConnection^ a = Connect();
	
	QueryTable("select * from fms.file_general;", a);
	EditTable("insert into fms.file_general values('12a','aqwe','wer',32,'sd',null,null,'asds','qwe',null,2,'12',0);", a);
	QueryTable("select * from fms.file_general;", a);
	Console::Read();
	return 0;
}


