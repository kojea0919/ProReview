#pragma once

#include <stdio.h>
#include "test1.h"
#include "test2.h"


//int iGlobal = 100;
//������ ������ ���� why?
//test.cpp ������ include�ϰ� �ִµ� �׷��� iGlobal ������ ����
//���������� ����� �����ϸ� �ȵȴ�.

//static
//����� �����ϴ� cpp���� ����!!!! �ش� ���������� ������ �ȴ�.
static int iGlobal1 = 100;
//test1 ���� �Ѱ� test2���� �Ѱ�

// extern
// ����� ������ �����ϴ� ������ �ƴ�
// �ܺ� cpp ���Ͽ� �ش� ������ ������ �˸���.!!
extern int iGlobal2;
//������ ��򰡿� �ؾ��Ѵ�.
//value�� include�ϴ� ��� cpp���� iGlobal2������ �����Ѵ�.