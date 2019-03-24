#include <Windows.h>
#include "my_string.h"

int my_strlen(WCHAR * string)
{
	int iCnt = 0;
	while (*string != '\0')
	{
		++iCnt;
		++string;
	}
	return iCnt;
}

int my_strlen(const WCHAR * string)
{
	int iCnt = 0;
	while (*string != '\0')
	{
		++iCnt;
		++string;
	}
	return iCnt;
}

bool my_strcpy_s(WCHAR * strDest, size_t Number, const WCHAR * strSrc)
{
	int iSrcLen = my_strlen(strSrc);
	int iDstLen = Number / sizeof(WCHAR);

	if (Number < iSrcLen * sizeof(WCHAR))
	{
		return false;
	}

	for (int iCnt = 0; iCnt < iDstLen; ++iCnt)
	{
		strDest[iCnt] = strSrc[iCnt];
	}

	return true;
}

int my_strcmp(const WCHAR * string1, const WCHAR * string2)
{
	while (*string1 != '\0' && *string2 != '\0')
	{
		if (*string1 < *string2)
			return -1;
		else if (*string1 > *string2)
			return 1;
		++string1;
		++string2;
	}
	return 0;
}

bool my_strcat_s(WCHAR * strDest, size_t Number, const WCHAR * strAdd)
{
	int iDstLen = my_strlen(strDest);
	int iBufferLen = Number / sizeof(WCHAR);
	int iAddLen = my_strlen(strAdd);
	int iIdx = 0;

	if (iDstLen + iAddLen + 1 > iBufferLen)//null문자까지 계산
		return false;

	for (int iCnt = iDstLen; iCnt < iDstLen + iAddLen; ++iCnt)
	{
		strDest[iCnt] = strAdd[iIdx++];
	}
	strDest[iDstLen + iAddLen] = L'\0';

	return true;
}

WCHAR * my_strchr(WCHAR * string, int c)
{
	int iLen = my_strlen(string);

	for (int iCnt = 0; iCnt < iLen; ++iCnt)
	{
		if (*string == c)
			return string;
		++string;
	}
	return nullptr;
}

WCHAR * my_strstr(WCHAR * string, const WCHAR * search)
{
	int iLen = my_strlen(string);
	int iSearchLen = my_strlen(search);

	int iCorrectCount = 0;

	for (int iCnt = 0; iCnt < iLen; ++iCnt)
	{
		if (iCorrectCount == iSearchLen)
		{
			for (int iCnt = 0; iCnt < iSearchLen; ++iCnt)
				--string;
			return string;
		}
		else if (*string == search[iCorrectCount])
			++iCorrectCount;

		else
			iCorrectCount = 0;
		++string;
	}

	return nullptr;
}
