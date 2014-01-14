#include "stdafx.h"
#include "Tools.h"
#include "ReadDirectoryChangesPrivate.h"
#include "ReadDirectoryChanges.h"

using namespace System;
using namespace System::Runtime::InteropServices;


CStringW ExplainAction(DWORD dwAction);
bool TryGetKeyboardInput(HANDLE hStdIn, bool &bTerminate, char* buf);
void InitiateMonitor();

