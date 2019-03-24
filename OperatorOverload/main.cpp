#include <iostream>

using namespace std;

//���� ����
//a�� ��������� �����Ͱ� �ִٰ� �ϰ�
//CA a;
//CA b(a);
//a=b;
//CA c = a+b;
//���� �ڵ尡 ����� �۵��Ǵ� Ŭ������ �ۼ��ϼ���.
//�������� ���� Ʋ����.
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
	//���Կ����ڴ� friend�Լ��� ����ϸ� �ȵȴ�.
	//��??
	//friend�Լ��� ����� ���� static�Լ��� �ȴ�.
	//�Լ������� static �������� �ٲ� �� �ְ� �Ǵµ�
	//���� �������� ������ �ڱⰪ�� ���ڷ� ���� ��ü�� ������
	//�ٲ��ִ� ���̹Ƿ� friend�Լ��� ������ �� ����.
	CA& operator =(const CA & other);
};





//���� ++�̳� --�� �����ε��� �� �����ؾ��ϴ� ��
//return�� const���ؼ� (a++)++;�̷�������
//����ϴ� ���� ������ �����Ѵ�.


//�̴ϼȶ������� �̿��ؼ� ����� �ʱ�ȭ�ϸ�
//�Լ� ȣ���� ���� 1ȸ ���� �� �ִ�.?
class Test
{
	int x;
public:
	Test() {}
	//Test(int a) : x(a) { }
	Test(int a) { x = a; }
	~Test() {}

public: 
	//�� ���۷��� Ÿ���̿��� �ϴ°�?
	//���� �ƴѵ� ������ �ȳ���
	//�׷� ���۷��������ϴ� ��찡 �ִ°� �ƴұ�?
	Test& operator <<(int _x)
	{
		printf("%d ", _x);
		return *this;
	}
};


int main()
{
	//+������, ���� ����, =������
	CA a(1);
	CA b(2);
	CA c = a+b;
	b = a;
	//CA c = a + b;











	//�̴ϼȶ������� �̿��ؼ� ����� �ʱ�ȭ�ϸ�
	//�Լ� ȣ���� ���� 1ȸ ���� �� �ִ�.?
	Test(1);
	//�𽺾����///////////////////////////
	//�̴ϼ� ������
	/*
	00CB195D  push        1  
	00CB195F  lea         ecx,[ebp+FFFFFF20h]  
	00CB1965  call        00CB13A7  
	������ ȣ��
	00CB17F0  push        ebp				//ebp����
	00CB17F1  mov         ebp,esp			//ebp�� esp(stackpoint)
	00CB17F3  sub         esp,0CCh			//�����Ҵ�
	00CB17F9  push        ebx
	00CB17FA  push        esi
	00CB17FB  push        edi
	00CB17FC  push        ecx
	00CB17FD  lea         edi,[ebp+FFFFFF34h]
	00CB1803  mov         ecx,33h
	00CB1808  mov         eax,0CCCCCCCCh	//cccccccc�� �о������
	00CB180D  rep stos    dword ptr es:[edi]
	00CB180F  pop         ecx
	00CB1810  mov         dword ptr [ebp-8],ecx
	00CB1813  mov         eax,dword ptr [ebp-8]	//eax�� ebp-8 ��� ����?
	00CB1816  mov         ecx,dword ptr [ebp+8]	//ecx�� �ۿ��� ������ 1 ����
	00CB1819  mov         dword ptr [eax],ecx
	00CB181B  mov         eax,dword ptr [ebp-8]
	00CB181E  pop         edi
	00CB181F  pop         esi
	00CB1820  pop         ebx
	00CB1821  mov         esp,ebp
	00CB1823  pop         ebp
	00CB1824  ret         4

	*/

	//<< ������
	Test t1;
	t1 << 1 << 2 << 3 << 4;



	//new ������
	Test * t = new Test;
	//new�����ڴ� �޸� ���� �Ҵ� �� ������ ȣ��
	//��� �޸� ������ �Ҵ縸 �ϰ�
	//���� �ڵ��ٿ� ������ ȣ�� �ڵ尡 ����.

	//����Ʈ ������
	//Dangling Pointer�� ���� �޸� ���� ������ ������ �� �ִ�.
	//shared_ptr�� ����Ʈ �����ʹ� ���� ī���� �������
	//Ư�� �ڿ��� ����Ű�� ���� ī��Ʈ�� �����ϰ� �ִٰ� �̰���
	//0�� �Ǹ� �ش� �ڿ��� �ڵ����� ������ �ִ� ����Ʈ ������
	//��� ���� ī��Ʈ�� �����ϴ°�?
	//���ο� int * Ref�� �ּ� � ���� ���� ����Ű�� �ִ� �ͳ���
	//Ref�� ���� ���� ����Ű���� �����ϸ� �ȴ�.



	return 0;
}

CA operator+(const CA & c1, const CA & c2)
{
	return CA(*(c1._pX) + *(c2._pX));
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
}

CA & CA::operator=(const CA & other)
{
	*_pX = *(other._pX);
	return *this;
}
