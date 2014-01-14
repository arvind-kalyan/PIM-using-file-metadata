#include"stdafx.h"
#include"FileDetail.h"
#include"db_connect.h"
#include <string>
using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Security::Cryptography;
using namespace System::Runtime::InteropServices;

// Print the byte array in a readable format. 
String^ StringfromByteArray(array<Byte>^array);

// load  directory structure into database
int readDir(String^ dir);

char** copies=(char**)malloc(100*sizeof(char*));

