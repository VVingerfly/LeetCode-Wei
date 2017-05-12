//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Feb/13 11:26:24
// Last Change  : 2017/Feb/13 11:26:26
// Summary      :
//===============================================================

#pragma once

#include <iostream>
using std::cout;
using std::endl;

//#define RUN_TEST_ALL

#ifdef RUN_TEST_ALL
#define RUN_TEST_Q1
#define RUN_TEST_Q2
#define RUN_TEST_Q3

#else
#define RUN_TEST_Q3
#endif



//===============================================================
#ifdef RUN_TEST_Q1
#include "Q1_TwoSum/Q1_TwoSum.h"
#pragma comment(lib, "Q1_TwoSum.lib")
#endif

//===============================================================
#ifdef RUN_TEST_Q2
#include "Q2_AddTwoNums/Q2_AddTwoNums.h"
#pragma comment(lib, "Q2_AddTwoNums.lib")
#endif

//===============================================================
#ifdef RUN_TEST_Q3
#include "Q3_LongestSubstring/Q3_LongestSubstring.h"
#pragma comment(lib, "Q3_LongestSubstring.lib")
#endif
//===============================================================




void test()
{
#ifdef RUN_TEST_Q1
	cout << "====================== Solution 1 =============================" << endl;
	testQ1();
	cout << "===============================================================" << endl << endl;
#endif //RUN_TEST_Q1

#ifdef RUN_TEST_Q2
	testQ2();
#endif //RUN_TEST_Q2

#ifdef RUN_TEST_Q3
	testQ3();
#endif //RUN_TEST_Q3

}