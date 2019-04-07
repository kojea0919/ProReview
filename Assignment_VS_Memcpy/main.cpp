#include <iostream>
#include <cstring>
#include <Windows.h>
#include <MMSystem.h>
#include <timeapi.h>

using namespace std;

#pragma comment(lib,"winmm.lib")

int main()
{
	int arr[4];
	int temp1[4];
	int temp2[4];

	for (int i = 0; i < 4; ++i)
		arr[i] = i;

	
	//´ëÀÔ
	for (int i = 0; i < 4; ++i)
	{
		temp1[i] = arr[i];
	}
	//memcpy
	memcpy(temp2, arr, sizeof(int) * 4);


	int a = 1;
	return 0;
}