#include <iostream>

using namespace std;

//면접 문제
//a의 멤버변수로 포인터가 있다고 하고
//CA a;
//CA b(a);
//a=b;
//CA c = a+b;
//위의 코드가 제대로 작동되는 클래스를 작성하세요.
//생각보다 많이 틀린다.
class CA
{
private:
	int * _pX;
public:
	CA() { _pX = new int; }
	CA(int iX) { _pX = new int; *_pX = iX; }
	CA(const CA & _other)
	{
		_pX = new int;
		*_pX = *(_other._pX);
	}

	~CA() { delete _pX; }

public:
	friend CA operator +(const CA & c1, const CA & c2);
	//friend CA& operator =(const CA & c1,const CA & c2);
	//대입연산자는 friend함수를 사용하면 안된다.
	//왜??
	//friend함수를 사용한 순간 static함수가 된다.
	//함수내에서 static 변수값만 바꿀 수 있게 되는데
	//대입 연산자의 목적은 자기값을 인자로 들어온 객체의 값으로
	//바꿔주는 것이므로 friend함수로 구현될 수 없다.
	CA& operator =(const CA & other);
};





//후위 ++이나 --를 오버로딩할 때 조심해야하는 점
//return을 const로해서 (a++)++;이런식으로
//사용하는 것을 오류를 내야한다.


//이니셜라이저를 이용해서 멤버를 초기화하면
//함수 호출의 수를 1회 줄일 수 있다.?
class Test
{
	int x;
public:
	Test() {}
	//Test(int a) : x(a) { }
	Test(int a) { x = a; }
	~Test() {}

public: 
	//꼭 레퍼런스 타입이여야 하는가?
	//꼭은 아닌듯 오류는 안난다
	//그럼 레퍼런스여야하는 경우가 있는거 아닐까?
	Test& operator <<(int _x)
	{
		printf("%d ", _x);
		return *this;
	}
};


int main()
{
	//+연산자, 깊은 복사, =연산자
	CA a(1);
	CA b(2);
	CA c = a+b;
	b = a;
	//CA c = a + b;











	//이니셜라이저를 이용해서 멤버를 초기화하면
	//함수 호출의 수를 1회 줄일 수 있다.?
	Test(1);
	//디스어셈블리///////////////////////////
	//이니셜 라이즈
	/*
	00CB195D  push        1  
	00CB195F  lea         ecx,[ebp+FFFFFF20h]  
	00CB1965  call        00CB13A7  
	생성자 호출
	00CB17F0  push        ebp				//ebp저장
	00CB17F1  mov         ebp,esp			//ebp에 esp(stackpoint)
	00CB17F3  sub         esp,0CCh			//공간할당
	00CB17F9  push        ebx
	00CB17FA  push        esi
	00CB17FB  push        edi
	00CB17FC  push        ecx
	00CB17FD  lea         edi,[ebp+FFFFFF34h]
	00CB1803  mov         ecx,33h
	00CB1808  mov         eax,0CCCCCCCCh	//cccccccc로 밀어버리기
	00CB180D  rep stos    dword ptr es:[edi]
	00CB180F  pop         ecx
	00CB1810  mov         dword ptr [ebp-8],ecx
	00CB1813  mov         eax,dword ptr [ebp-8]	//eax에 ebp-8 멤버 변수?
	00CB1816  mov         ecx,dword ptr [ebp+8]	//ecx에 밖에서 저장한 1 저장
	00CB1819  mov         dword ptr [eax],ecx
	00CB181B  mov         eax,dword ptr [ebp-8]
	00CB181E  pop         edi
	00CB181F  pop         esi
	00CB1820  pop         ebx
	00CB1821  mov         esp,ebp
	00CB1823  pop         ebp
	00CB1824  ret         4

	*/

	//<< 연산자
	Test t1;
	t1 << 1 << 2 << 3 << 4;



	//new 연산자
	Test * t = new Test;
	//new연산자는 메모리 공간 할당 및 생성자 호출
	//사실 메모리 공간의 할당만 하고
	//다음 코드줄에 생성자 호출 코드가 들어간다.

	//스마트 포인터
	//Dangling Pointer로 인해 메모리 누수 현상을 방지할 수 있다.
	//shared_ptr의 스마트 포인터는 참조 카운팅 방식으로
	//특정 자원을 가리키는 참조 카운트를 유지하고 있다가 이것이
	//0이 되면 해당 자원을 자동으로 삭제해 주는 스마트 포인터
	//어떻게 참조 카운트를 유지하는가?
	//내부에 int * Ref를 둬서 어떤 같은 값을 가리키고 있는 것끼리
	//Ref가 같은 값을 가리키도록 구현하면 된다.



	return 0;
}

CA operator+(const CA & c1, const CA & c2)
{
	return CA(*(c1._pX) + *(c2._pX));
	// TODO: 여기에 반환 구문을 삽입합니다.
}

CA & CA::operator=(const CA & other)
{
	*_pX = *(other._pX);
	return *this;
}
