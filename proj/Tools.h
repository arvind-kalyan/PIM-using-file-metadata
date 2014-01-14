#include"stdafx.h"
#include<stdio.h>
#include<iostream>
#include <stdlib.h>


using namespace System;

void SetCurrentUser(String^ name);

String^ GetCurrentUser();

void LogDetectedChange(char* message);

int AddUser(String^ user, String^ name, String^ password, String^ devices);

int LogUser(String^ user, String^ password);

int GetRepository(array<String^>^ ret);

void AddRepository(String^ dir);

void RemoveRepository(String^ dir);

void UpdateFileintoRepository(String^ message);


String^ FindAbsolutePath(String^ filename,String^ parent);

String^ PrintFileMetadata(String^ filename);

String^ GetHash(String^ filename);

int SearchResult(String^ text);


