#pragma once

#include <stdio.h>
#include "test1.h"
#include "test2.h"


//int iGlobal = 100;
//재정의 컴파일 오류 why?
//test.cpp 에서도 include하고 있는데 그러면 iGlobal 여러번 정의
//전역변수는 헤더에 선언하면 안된다.

//static
//헤더를 참조하는 cpp들이 각자!!!! 해당 전역변수를 가지게 된다.
static int iGlobal1 = 100;
//test1 에도 한개 test2에도 한개

// extern
// 헤더에 변수를 선언하는 목적이 아님
// 외부 cpp 파일에 해당 변수가 있음을 알린다.!!
extern int iGlobal2;
//선언은 어딘가에 해야한다.
//value를 include하는 모든 cpp들은 iGlobal2변수를 공유한다.