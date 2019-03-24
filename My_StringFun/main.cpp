#include <iostream>
#include <cstring>
#include <Windows.h>
#include "my_string.h"
using namespace std;

int my_strlen(WCHAR * string);

int wmain(int argc,WCHAR * argv)
{
	int iLen;
	WCHAR string[20] = L"ABCDEFGHIJKLMNOP";
	WCHAR *  test = L"MNOz";
	WCHAR * pStr;

	int ic = L' ';

	pStr = my_strstr(string, test);
	
	return 0;
}
