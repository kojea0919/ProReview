#include <iostream>

using namespace std;

//ebp : Extended Base Pointer
//�� ���� �������� ���� �ּҸ� ����Ų��.
//���� �����Ѱŷ� �����ϸ� fp(frame pointer)

//esp : Extended Stack Pointer
//�� ������ ������
//���ÿ� Push�� �� �ִ� �� ��ġ

//eax : Extended Accumulator Register
//��� �� ���꿡 ����ϴ� ��������
//CPU���� ��� �� ������ ����ϴ� �κ���
//ALU(Arithmetic Logic Unit)

//ecx : Extended Counter Register
//�ݺ��� ���� ī������ ���� ��������

//////////////////////////////////////////////
//esi : Extended Source index				//
//������ ����� ���� �ּ�					//
											//�� �ΰ��� �������ʹ�
//edi ; Extended Destination index			//memcpy�� �޸� ������ ��
//������ ����� ������ �ּ�					//
//////////////////////////////////////////////

void test(int _iX)
{
	cout << "X : " << _iX << endl;
}


int main()
{
	//1. �������� ���� �𽺾���� Ȯ��


	
	//int a1 = 1;
	//int a2 = 2;
	//int a3 = 3;
	//
	//cin >> a1;


	//�������� ����
	//���� ���������� �Ҵ��̶�� ������ ������?
	//�𽺾������ Ȯ���غ���

	/*
	00DF16D0  push        ebp			�����Լ� �������ڸ��� ebp�� push���ְ� ������ Ȯ��
	00DF16D1  mov         ebp,esp		esp�� �ʱ�ȭ ���ְ� ����
	00DF16D3  sub         esp,0E4h		�̺κ��� �����Լ��� ���� ���� ���� �Ҵ� 228��ŭ �Ҵ��ߴ�.
	00DF16D9  push        ebx			debug���� 228���� release���� ���� ũ�⸸ŭ �Ҵ��� ���̴�.
	00DF16DA  push        esi  
	00DF16DB  push        edi  
	00DF16DC  lea         edi,[ebp-0E4h]  
	00DF16E2  mov         ecx,39h				ecx�� �ݺ����� ���� �������� 39 -> 57
	00DF16E7  mov         eax,0CCCCCCCCh		
	00DF16EC  rep stos    dword ptr es:[edi]	������ cccccccc�� �о� ������ ��
		int a1 = 1;
	00DF16EE  mov         dword ptr [ebp-8],1   ���� �ٿ� ���� ������ �Ҵ��� �ƴ϶�
		int a2 = 2;								�޸��� ��ġ�� ������ �����Ѵ�.
	00DF16F5  mov         dword ptr [ebp-14h],2  
		int a3 = 3;
	00DF16FC  mov         dword ptr [ebp-20h],3  
		return 0;
	00DF1703  xor         eax,eax  
	*/
	////////////////////////////////////////////////////////////////////////////////////////////

	//2. �Լ� ���ڿ� ���� ����� Ȯ��
	test(10);


	/*
	00AB24EE  push        0Ah  
	00AB24F0  call        00AB13B6  

	���⼭ Jump�߻��Ѵ�.
	add�κ��� test�Լ� ��ȯ�ǰ� ���ĺ��� �����
	00AB24F5  add         esp,4  
	
	jump
	//�����ִ� �κ��� �Լ��� ���ںκ��̹Ƿ�
	�տ� �κи� ���캸���� �ϰڽ��ϴ�.

	00AB2440  push        ebp					ebp esp�� �ʱ�ȭ�ϴ���
	00AB2441  mov         ebp,esp
	00AB2443  sub         esp,0C0h				�Լ��� ���� �޸𸮸� ����Ͽ� esp�� �ø�
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
	00AB2467  mov         eax,dword ptr [ebp+8]	���� ������� �ٸ��� +���� �� �Լ� �ܺο� �ִ�
												���ÿ� �����ؼ� ������ �����´�.
												�״ϱ� ���ڴ� �޸𸮸� ���� �Ҵ����� �ʴ´�?

	�Լ� ���� ��

	00AB249D  pop         edi
	00AB249E  pop         esi
	00AB249F  pop         ebx
	00AB24A0  add         esp,0C0h				//esp�� �����ְ�
	00AB24A6  cmp         ebp,esp				//ebp���� esp
	00AB24A8  call        00AB114F
	00AB24AD  mov         esp,ebp				//esp = ebp�� �ְ� -> test�Լ� �����ϱ� ���� ��ġ�� ����ؼ� �����ش�.
	00AB24AF  pop         ebp					//test�Լ��� �����Ƿ� ebp pop

	*/


	return 0;
}