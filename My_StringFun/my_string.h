#pragma once

int my_strlen(WCHAR * string);

int my_strlen(const WCHAR * string);

bool my_strcpy_s(WCHAR * strDest, size_t Number, const WCHAR * strSrc);

int my_strcmp(const WCHAR * string1, const WCHAR * string2);

bool my_strcat_s(WCHAR * strDest, size_t Number, const WCHAR * strAdd);

WCHAR * my_strchr(WCHAR * string, int c);

WCHAR * my_strstr(WCHAR * string, const WCHAR * search);