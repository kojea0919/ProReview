#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;


#pragma comment(lib,"winmm.lib")

int main()
{
	// 시간관련 함수들의 test코드



	/*
	/////////////////////////
	// 1. localtime_s 함수 //
	/////////////////////////

	tm _tm;
	time_t t = time(NULL);
	localtime_s(&_tm, &t);

	//tm 구조체에 현재 초,분,시간,날짜,달.. 등의 정보가 저장된다.
	////////////////////////////////////////////////////////////////
	//------------------------------------------------------------//
	////////////////////////////////////////////////////////////////

	*/



	/*


	/////////////////////////
	//2. GecTickCount 함수 //
	/////////////////////////

	//좀더 높은 해상도의 timer이다.
	
	//함수의 원형은 DWORD GetTickCount();로
	//운영체제가 시작되어서 지금까지 흐른 시간을 1/1000초 단위의
	//DWORD형으로 반환하는 함수다.

	DWORD dwStart = GetTickCount();
	DWORD dwCur;

	//timeBeginPeriod(1000);

	while (true)
	{
		dwCur = GetTickCount();
		cout << (dwCur - dwStart) / 1000.0 << endl;
	}

	//timeEndPeriod(1000);

	//하지만 위의 코드를 실행해보면 알겠지만 정말 밀리세컨드 단위로
	//Counting되지 않는다 즉 0.001초단위로 나오지 않는다는 것이다.
	//이유는 바로 time interval 떄문이다. 
	//윈도우의 기본 타이머 정확도는 15.625 msec로 약 15msec간격으로 시간을
	//체크한다. 즉 이 함수는 엄밀히 따지면 msec를 측정할 수 있는 함수는 아니다.

	////////////////////////////////////////////////////////////////
	//------------------------------------------------------------//
	////////////////////////////////////////////////////////////////


	*/



	/*
	///////////////////////////
	//3. GecTickCount64 함수 //
	///////////////////////////

	// 위의 GetTickCount의 다른 버전의 함수로 GetTickCount는
	//49.7일이 지난 시점부터는 값이 0으로 초기화 된다는 단점이 있다.
	//이를 보안해서 나온 함수가 GetTickCount64로 안심하고 사용할 수 있다.
	
	////////////////////////////////////////////////////////////////
	//------------------------------------------------------------//
	////////////////////////////////////////////////////////////////
	*/


	/*

	/////////////////////////
	// 5. timeGetTime 함수 //
	/////////////////////////


	//GetTickCount는 time interval 때문에 msec단위로 정확하게
	//갱신할 수 없다고 설명했다. timeGetTime은 이를 보완하여
	//정말 msec단위로 반환해주는 함수이다. 
	//이때 필요한 것은 #pragma comment(lib,"winmm.lib")를 넣어줘야 한다
	//즉 winmm.lib를 링크 시켜줘야 한다는 것이다.
	//또한 time interval을 1 msec로 바꿔줄 함수 
	//timeBeginPeriod(1) : 설정해주는 함수
	//timeEngPeriod(1)   : 해제해주는 함수
	//위의 두 함수가 앞 뒤로 들어가야한다.

	DWORD dwStart = timeGetTime();
	DWORD dwCur;
	timeBeginPeriod(1);


	while (true)
	{
		dwCur = timeGetTime();

		cout << (dwCur - dwStart) / 1000.0 << endl;
	}
	timeEndPeriod(1);

	//위의 코드를 실행시켜보면 1msec단위로 체크가 되고 있음을 확인할 수 있다.


	////////////////////////////////////////////////////////////////
	//------------------------------------------------------------//
	////////////////////////////////////////////////////////////////

	*/




	/////////////////////////////////////
	// 5. QueryPerformanceCounter 함수 //
	/////////////////////////////////////

	//timeGetTime함수보다 더 고해상도의 타이머를 얻고 싶을 때 사용하는 함수로
	//현재로서는 가장 높은 해상도의 타이머이다.
	
	//이 함수에서는 몇가지 살펴봐야할 점이 존재한다.
	//멀티 코어에서 안전한가?
	//아니다 
	//이 함수는 CPU에 의존적이기 때문에 멀티스레드를 활용하는 프로그램에서
	//여러개의 스레드로 CPU가 분산되었을때 스레드가 동일한 시점에
	//QueryPerformanceCounter함수를 사용해서 값을 읽어도 서로 다른 값을 가져올 수 있다고 한다.
	
	LARGE_INTEGER Frequency;
	LARGE_INTEGER BeginTime;
	LARGE_INTEGER EndTime;


	QueryPerformanceFrequency(&Frequency);//주기 얻어오기
	
	QueryPerformanceCounter(&BeginTime);


	timeBeginPeriod(1);
	Sleep(1);
	timeEndPeriod(1);

	QueryPerformanceCounter(&EndTime);

	__int64 elapsed = EndTime.QuadPart - BeginTime.QuadPart;
	double durinttime = (double)elapsed / (double)Frequency.QuadPart;

	return 0;

}