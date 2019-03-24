#include <iostream>

using namespace std;

//1. 구조체
//c++ 에서 구조체는
//typedef 하지 않아도 됩니다.

//2. 클래스
class CPlayer//클래스 이름 앞에는 형식적으로 C를 붙여준다.
{
	//////////////
	enum A {	//
		A1,		//
		A2,		//클래스 내부에서만 사용 할 수 있도록
		A3		//enum을 정의할 수 있다.
	};			//
	//////////////

public:
	//지금까지는 멤버 변수는 private로 선언해서
	//외부에서 값을 바꿀 수 없도록 하는게 좋다고
	//했지만 너무 이것을 공식화 하지 말아야 한다.
	//모든 변수에 대해서 getter setter를 만들바엔
	//public으로 선언해서 접근하는게 더 좋다.
	//꼭 private해야 하는 변수만 private해주자
	//아래와 같은 코드가 있다고 하자

	//void Key...()
	//{
	//	if(왼쪽키)
	//	{
	//		int x = Player.Getx();
	//		Player.Set(x-1); 
	//	}
	//}
	//과연 이게 클래스를 잘 활용한 예인가?
	//아니다 이게 진짜 클래스를 잘 활용한 것이라면
	//아래와 같은 코드로 바뀌어야 할 것이다.
	
	//void Key...()
	//{
	//	if(왼쪽키)
	//	{
	//		Player.LeftMove();
	//	}
	//}
	//결론은 public으로 풀건 풀자는 얘기
public:
	char * _pBuffer;
	int	_b;
	int _c;

public:
	CPlayer()
	{
		cout << "생성자" << endl;
		_pBuffer = new char[10];
	}
	~CPlayer()
	{
		cout << "소멸자" << endl;
		delete[] _pBuffer;
	}

public:
	void test()
	{
		cout << "테스트용 입니다." << endl;
		_b = 1;
		_c = 2;
	}
};


int main()
{
	//아래에서 각각 생성자와 소멸자 호출 시점은?
	//CPlayer p1;	//생성자는 이때
				//소멸자는 return문 다음에서

	//if (true)
	//	CPlayer p2; //생성자는 이때
					//소멸자는 if문 나올때

	

	//다음과 같은 가정을 해보자
	//하나의 변수를 원할 때마다 정리를 하고 다시 초기화하는
	//방식으로 사용하고 싶다면 어떻게 해야할까?

	///////////////////////////////////////////////////////
	/*
	//1번 답
	CPlayer player;//생성자 호출에서 동적할당
	//
	//작업
	//
	player.~CPlayer();//동적할당 해제

	new(&player) CPlayer;//또 생성자 
	//
	//작업
	//
	//player.~CPlayer();//동적할당 해제
	//이 방법의 문제점
	//얼추보면 다 해제 시키는 것 같지만
	//return할때 또 소멸자를 호출시킨다 오류다.
	*/
	///////////////////////////////////////////////////////
	/*
	//2번 답
	CPlayer * player = (CPlayer*)malloc(sizeof(CPlayer));
	//new를 쓰면 생성자 호출하니까 new말고 malloc을 사용
	//Player 사용
	new (player) CPlayer;
	//Player 정리
	player->~CPlayer();
	//Player 사용
	new (&player) CPlayer;
	*/

	///////////////////////////////////////////////////////솔직히
	CPlayer p1;
	CPlayer *p2 = new CPlayer;
	//이 객체들의 멤버 함수는 어디에 있는가?
	//객체마다 함수가 있어서 코드영역에 따로 존재할까?
	//Nope p1의 함수던 p2의 함수던 같은 함수다
	//누구의 기준인지가 다른 것이다.

	//좀더 쉬운 이해를 위해서
	//Player의 함수에 test함수를 보자
	//test함수가 아래와 같이 선언돼있다고 생각하면 이해하기 쉬울 것이다.
	//void test(CPlayer * _pPlayer)
	//그리고 test함수를 호출하면 다음과 같이 호출한다고
	//생가하면 된다.
	//p1.test(this);
	//p2->test(this);

	p1.test();
	p2->test();
	//이 test함수를 디스어셈블리로 살펴보면 알 수 있는 것이 하나 있는데
	//p1에서 멤버 변수를 건드리는 것은 2단계를 거쳐서 함을 볼 수 있다.
	//p1으로 들어가서 eax에 this를 넣고 eax에서 멤버변수의 위치만큼
	//더해준 그 값을 건드리는 것을 확인할 수 있다.
	//따라서 멤버변수에 있는 그 값을 읽는 용도로 참조하는 용도로
	//사용을 한다고 하면 다음과 같이 사용하는 것이 옳은 방법이다.
	int Temp1 = p1._b;
	int Temp2 = p1._c;

	//Temp1 Temp2를 이용한 작업

	//직접 p1._b p1._c를 이용해서 작업하는 것은 2배의 많은 일을 만든다
	//값을 바꿀 것이 아니면 첫번째 방법을 사용합시다.
	return 0;
}