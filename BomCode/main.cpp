#include <stdio.h>
#include <wchar.h>
#include <locale.h>


int wmain(int argc, wchar_t * argv[])
{
	wchar_t buf[200];
	wchar_t test;
	_wsetlocale(LC_ALL, L"korean");

	FILE * fp;
	
	//bom코드 O
	//////////////////////////////////////////////////////
	_wfopen_s(&fp,L"hello.txt",L"w+,ccs=UTF-32");
	//////////////////////////////////////////////////////

	//bom코드 X
	//////////////////////////////////////////////////////
	//_wfopen_s(&fp, L"hello.txt", L"w+");
	//////////////////////////////////////////////////////


	fwprintf(fp, L"%s", L"Hello");

	//_wfopen_s(&fp, L"hello.txt", L"r,ccs=UTF-8");
	//_wfopen_s(&fp, L"hello.txt", L"r");

	//fwscanf_s(fp, L"%s", buf,200);

	//fclose(fp);

	//wprintf(L"%s", buf);


	//while (1)
	//{
	//	fwscanf_s(fp, L"%c", buf, 1);
	//	if (feof(fp))
	//		break;
	//	wprintf(L"%c", buf[0]);
	//}
	fclose(fp);
	return 0;
}