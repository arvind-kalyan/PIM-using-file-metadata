// FileDetail.cpp : retrieves file's metadata.

#include "stdafx.h"

#include <iostream>


#pragma comment (lib,"Gdiplus.lib")
using namespace std;
using namespace System;
using namespace System::IO;

using namespace System::Runtime::InteropServices;


String^ StringfromByteArray(array<Byte>^array);
//fetches attributes of the given file.
String^ getAttributes(FileInfo^ fi);

//fetches details of audio files
String^ calculateHash(String^ filename);
//fetches details of document files
void getDocumentDetails(FileInfo^ fi, string ext);

//fetches details of image files
void getImageDetails(FileInfo^ fi);
//gets general information of the given file
int getInfo(String^ name);

