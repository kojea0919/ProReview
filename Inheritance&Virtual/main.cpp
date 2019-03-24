#include <iostream>

using namespace std;

class A
{
public:
	A() { cout << "A 생성자" << endl; }
	~A() { cout << "A 소멸자" << endl; }

public:
	//void MyFunc() { cout << "A MyFunc()" << endl; }
	virtual void MyFunc() { cout << "A virtual MyFunc()" << endl; }
};

class B : public A
{
public:
	B() { cout << "B 생성자" << endl; }
	~B() { cout << "B 소멸자" << endl; }

public:
	//void MyFunc() { cout << "B MyFunc()" << endl; }
	virtual void MyFunc() { cout << "B virtual MyFunc()" << endl; }

};

class C : public B
{
public:
	C() { cout << "C 생성자" << endl; }
	~C() { cout << "C 소멸자" << endl; }

public:
	//void MyFunc() { cout << "C MyFunc()" << endl; }
	virtual void MyFunc() { cout << "C virtual MyFunc()" << endl; }

};

int main()
{
	// 1. 생성자 소멸자 호출 순서
	
	////////////////////
	//C c;
	////////////////////
	
	// 생성자 호출 순서는 부모 -> 자식 순으로 호출된다.
	// 소멸자 호출 순서는 자식 -> 부모 순으로 호출된다.

	// 참고
	// 상속은 클라이언트에서 많이 사용하지만
	// 서버는 Has - A 관계를 많이 이용한다.
	// Has-A 관계란 총을든 경찰을 class로 나타내고 싶을때
	// 물론 상속 관계도 가능하지만 Police 멤버 변수로 Gun을 가지도록
	// 할 수있다. 이때 Gun에서도 Police에 접근할 일이 생길 수도있으니
	// Gun도 Police를 가지게 하자. 즉 상호 참조 하도록 구현하자.

	// 2. 타입에 따른 다른 함수의 호출

	//////////////////////
	/*C * c = new C();
	B * b = c;
	A * a = c;

	c->MyFunc();
	b->MyFunc();
	a->MyFunc();*/
	//////////////////////

	// 각각의 클래스의 MyFunc를 호출한다
	// C::MyFunc(this) 이런식으로 호출하는 중

	

	// 3. virtual 함수
	

	////////////////////
	//A * a = new C();
	//a->MyFunc();
	////////////////////


	//위의 코드에서는  a의 MyFunc()가 호출된다.
	//여기서 C클래스의 MyFunc()를 호출하고 싶다면
	//virtual 키워드 즉 가상함수로 만들어야 한다.

	//함수 이름앞에 virtual keyword를 붙이는 것으로
	//가상함수를 만들 수 있다.


	
	// 4. 가상함수 테이블
	// 가상 함수를 가지고 있는 클래스는 내부에 가상함수 테이블을
	// 가리키는 4byte 또는 8byte 포인터가 생성된다.
	// 간단하게 배열로 구현돼있고 virtual이 붙은 순서대로 생긴다.
	// 아래의 A클래스를 확인해보자.


	A a1;
	cout << sizeof(a1) << endl;//크기 4 출력
	A a2;
	A a3;
	A a4;

	a1.MyFunc();
	// _vfptr이란 포인터가 가상함수 테이블을 가리키고 있는중이다.

	return 0;
}