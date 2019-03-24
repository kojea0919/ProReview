#include <iostream>

using namespace std;

//ebp : Extended Base Pointer
//현 스택 프레임의 시작 주소를 가리킨다.
//내가 공부한거로 생각하면 fp(frame pointer)

//esp : Extended Stack Pointer
//현 스택의 포인터
//스택에 Push될 수 있는 현 위치

//eax : Extended Accumulator Register
//산술 논리 연산에 사용하는 레지스터
//CPU에서 산술 논리 연산을 담당하는 부분은
//ALU(Arithmetic Logic Unit)

//ecx : Extended Counter Register
//반복문 등의 카운팅을 위한 레지스터

//////////////////////////////////////////////
//esi : Extended Source index				//
//데이터 복사시 원본 주소					//
											//이 두개의 레지스터는
//edi ; Extended Destination index			//memcpy등 메모리 연산할 때
//데이터 복사시 목적지 주소					//
//////////////////////////////////////////////

void test(int _iX)
{
	cout << "X : " << _iX << endl;
}


int main()
{
	//1. 변수선언에 대한 디스어셈블리 확인


	
	//int a1 = 1;
	//int a2 = 2;
	//int a3 = 3;
	//
	//cin >> a1;


	//지역변수 선언
	//과연 지역변수에 할당이라는 개념이 있을까?
	//디스어셈블리로 확인해보자

	/*
	00DF16D0  push        ebp			메인함수 시작하자마자 ebp를 push해주고 있음을 확인
	00DF16D1  mov         ebp,esp		esp도 초기화 해주고 있음
	00DF16D3  sub         esp,0E4h		이부분이 메인함수를 위한 스택 공간 할당 228만큼 할당했다.
	00DF16D9  push        ebx			debug모드라서 228이지 release모드면 원래 크기만큼 할당할 것이다.
	00DF16DA  push        esi  
	00DF16DB  push        edi  
	00DF16DC  lea         edi,[ebp-0E4h]  
	00DF16E2  mov         ecx,39h				ecx는 반복문을 위한 레지스터 39 -> 57
	00DF16E7  mov         eax,0CCCCCCCCh		
	00DF16EC  rep stos    dword ptr es:[edi]	공간을 cccccccc로 밀어 버리는 중
		int a1 = 1;
	00DF16EE  mov         dword ptr [ebp-8],1   보는 바와 같이 변수의 할당이 아니라
		int a2 = 2;								메모리의 위치로 변수에 접근한다.
	00DF16F5  mov         dword ptr [ebp-14h],2  
		int a3 = 3;
	00DF16FC  mov         dword ptr [ebp-20h],3  
		return 0;
	00DF1703  xor         eax,eax  
	*/
	////////////////////////////////////////////////////////////////////////////////////////////

	//2. 함수 인자에 대한 어셈블리 확인
	test(10);


	/*
	00AB24EE  push        0Ah  
	00AB24F0  call        00AB13B6  

	여기서 Jump발생한다.
	add부분은 test함수 반환되고 이후부터 실행됨
	00AB24F5  add         esp,4  
	
	jump
	//관심있는 부분은 함수의 인자부분이므로
	앞에 부분만 살펴보도록 하겠습니다.

	00AB2440  push        ebp					ebp esp를 초기화하는중
	00AB2441  mov         ebp,esp
	00AB2443  sub         esp,0C0h				함수가 쓰는 메모리를 계산하여 esp를 올림
	00AB2449  push        ebx
	00AB244A  push        esi
	00AB244B  push        edi
	00AB244C  lea         edi,[ebp+FFFFFF40h]
	00AB2452  mov         ecx,30h
	00AB2457  mov         eax,0CCCCCCCCh
	00AB245C  rep stos    dword ptr es:[edi]
	cout << "X : " << _iX << endl;
	00AB245E  mov         esi,esp
	00AB2460  push        0AB107Dh
	00AB2465  mov         edi,esp
	00AB2467  mov         eax,dword ptr [ebp+8]	이전 연산과는 다르게 +연산 즉 함수 외부에 있는
												스택에 접근해서 변수를 가져온다.
												그니까 인자는 메모리를 따로 할당하지 않는다?

	함수 끝난 후

	00AB249D  pop         edi
	00AB249E  pop         esi
	00AB249F  pop         ebx
	00AB24A0  add         esp,0C0h				//esp를 내려주고
	00AB24A6  cmp         ebp,esp				//ebp에는 esp
	00AB24A8  call        00AB114F
	00AB24AD  mov         esp,ebp				//esp = ebp를 넣고 -> test함수 끝나니까 이전 위치를 기억해서 보내준다.
	00AB24AF  pop         ebp					//test함수가 끝나므로 ebp pop

	*/


	return 0;
}