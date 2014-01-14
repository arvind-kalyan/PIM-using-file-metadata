// ConsoleApplication2.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Runtime::InteropServices;


MySqlConnection^ Connect();

int EditTable(String^ statement, MySqlConnection^ conn);

MySqlDataReader^ QueryTable(String^ statement, MySqlConnection^ conn);




