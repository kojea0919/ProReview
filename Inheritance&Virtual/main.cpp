#include <iostream>

using namespace std;

class A
{
public:
	A() { cout << "A ������" << endl; }
	~A() { cout << "A �Ҹ���" << endl; }

public:
	//void MyFunc() { cout << "A MyFunc()" << endl; }
	virtual void MyFunc() { cout << "A virtual MyFunc()" << endl; }
};

class B : public A
{
public:
	B() { cout << "B ������" << endl; }
	~B() { cout << "B �Ҹ���" << endl; }

public:
	//void MyFunc() { cout << "B MyFunc()" << endl; }
	virtual void MyFunc() { cout << "B virtual MyFunc()" << endl; }

};

class C : public B
{
public:
	C() { cout << "C ������" << endl; }
	~C() { cout << "C �Ҹ���" << endl; }

public:
	//void MyFunc() { cout << "C MyFunc()" << endl; }
	virtual void MyFunc() { cout << "C virtual MyFunc()" << endl; }

};

int main()
{
	// 1. ������ �Ҹ��� ȣ�� ����
	
	////////////////////
	//C c;
	////////////////////
	
	// ������ ȣ�� ������ �θ� -> �ڽ� ������ ȣ��ȴ�.
	// �Ҹ��� ȣ�� ������ �ڽ� -> �θ� ������ ȣ��ȴ�.

	// ����
	// ����� Ŭ���̾�Ʈ���� ���� ���������
	// ������ Has - A ���踦 ���� �̿��Ѵ�.
	// Has-A ����� ������ ������ class�� ��Ÿ���� ������
	// ���� ��� ���赵 ���������� Police ��� ������ Gun�� ��������
	// �� ���ִ�. �̶� Gun������ Police�� ������ ���� ���� ����������
	// Gun�� Police�� ������ ����. �� ��ȣ ���� �ϵ��� ��������.

	// 2. Ÿ�Կ� ���� �ٸ� �Լ��� ȣ��

	//////////////////////
	/*C * c = new C();
	B * b = c;
	A * a = c;

	c->MyFunc();
	b->MyFunc();
	a->MyFunc();*/
	//////////////////////

	// ������ Ŭ������ MyFunc�� ȣ���Ѵ�
	// C::MyFunc(this) �̷������� ȣ���ϴ� ��

	

	// 3. virtual �Լ�
	

	////////////////////
	//A * a = new C();
	//a->MyFunc();
	////////////////////


	//���� �ڵ忡����  a�� MyFunc()�� ȣ��ȴ�.
	//���⼭ CŬ������ MyFunc()�� ȣ���ϰ� �ʹٸ�
	//virtual Ű���� �� �����Լ��� ������ �Ѵ�.

	//�Լ� �̸��տ� virtual keyword�� ���̴� ������
	//�����Լ��� ���� �� �ִ�.


	
	// 4. �����Լ� ���̺�
	// ���� �Լ��� ������ �ִ� Ŭ������ ���ο� �����Լ� ���̺���
	// ����Ű�� 4byte �Ǵ� 8byte �����Ͱ� �����ȴ�.
	// �����ϰ� �迭�� �������ְ� virtual�� ���� ������� �����.
	// �Ʒ��� AŬ������ Ȯ���غ���.


	A a1;
	cout << sizeof(a1) << endl;//ũ�� 4 ���
	A a2;
	A a3;
	A a4;

	a1.MyFunc();
	// _vfptr�̶� �����Ͱ� �����Լ� ���̺��� ����Ű�� �ִ����̴�.

	return 0;
}