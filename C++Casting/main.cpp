#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <stdio.h>
#include <cstring>

using namespace std;

int my_strlen(char * string);


class Base
{
	int x;
	int y;
public:
	Base() {}
	virtual ~Base() {}

	void test()
	{
		cout << x << endl;
	}
};

class Derived : public Base
{
	int y;
public:
	Derived() {}
	virtual ~Derived() {}
	
	void test()
	{
		cout << y << endl;
	}
};

class Other
{
	double a;
public:
	Other() {}
	~Other() {}
};

class AAA
{
public:
	AAA() { cout << "생성자 입니다." << endl; ++iUnitCnt; }
	~AAA() { cout << "소멸자 입니다." << endl; --iUnitCnt;	}

	static int iUnitCnt;
};
int AAA::iUnitCnt = 0;


void main()
{
	////////////////////////////////////////////////////////
	Base * b = new Base();
	Derived * d = dynamic_cast<Derived*>(b);
	Other * o = dynamic_cast<Other*>(b);
	////////////////////////////////////////////////////////
	//NULL값

	////////////////////////////////////////////////////////
	Derived * d1 = new Derived();
	b = d1;
	Derived * d2 = dynamic_cast<Derived*>(b);
	////////////////////////////////////////////////////////
	//제대로된 값
	
	////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////
	b = new Base();
	d = static_cast<Derived*>(b);
	////////////////////////////////////////////////////////
	//NULL값
	
	//o = static_cast<Other*>(b);
	//컴파일 에러

	////////////////////////////////////////////////////////
	d1 = new Derived();
	b = d1;
	d2 = static_cast<Derived*>(b);
	////////////////////////////////////////////////////////
	//제대로된 값


	////////////////////////////////////////////////////////
	int * iValue = reinterpret_cast<int*>(b);
	
	o = reinterpret_cast<Other*>(b);
	////////////////////////////////////////////////////////


	int test = 10;
	const int * a = &test;
	//a = const_cast<int>(a);

	int * value1 = const_cast<int*>(a);
	++(*value1);

	const int value2 = 20;
	int value3 = const_cast<int>(value2);



	//AAA* aaa = new AAA();
	//delete aaa;
	//AAA a;

	//int al = AAA::iUnitCnt;
}

int my_strlen(char * string)
{
	int iCnt = 0;
	while (string[iCnt] != '\0')
	{
		iCnt++;
	}
	return iCnt;
}
