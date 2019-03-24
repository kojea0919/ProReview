#include "value.h"


// 전역변수
// 1. 프로그램 시작 시점에 초기화
// 2. 프로그램 종료 시 해제

int iGlobal2 = 50;//extern 어딘가에 선언

int main()
{
	//문자열 표시방법 2가지
	//1. 배열
	// 원본(코드영역)따로 저장된 곳(스택영역) 따로
	char arrString[20] = "Hello World!";
	//2. 포인터
	// 얘는 코드영역에 할당된 주소를 포인터가 가리킨다.
	char* pString = "Hello World!";//따라서 얘는 수정 불가능!!

	printf("%s\n", arrString);
	printf("%s\n", pString);
	//printf 주소값으로 인자가 들어왔을 경우에는
	//가리키는 곳으로 가서 null을 만날때 까지 문자열을 읽어온다.

	// 1. Data 영역 전역변수, static
 	// 2. 스택 영역 지역변수
	// 3. 힙   영역 동적할당
	// 4. 코드 영역 --> exe 파일 이진코드가 메모리상에 올라가있는 영역
				   
	// 변수의 종류 
	// 1. 지역 변수(스택메모리, 함수)
	// 2. 전역 변수(Data 영역)
	// 3. 정적 변수(static)
	// 4. 외부 변수(extern)
				   
	iGlobal1 = 50; 
	test1();
	test2();

	
	_test1();
	_test2();

	return 0;
}