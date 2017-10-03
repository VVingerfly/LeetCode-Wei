#include <iostream>
#include "./LeetCode/LeetCode.h"
#include "./Sort/sort_algo.h"

#define RUN_
#ifdef RUN_



using namespace std;
//#define TEST_SORT
#define TEST_LeetCode

int main()
{
#ifdef TEST_LeetCode
	cout << "LeetCode --------------------------" << endl;
	//TestQ3();
	//TestQ4();
	//TestQ5();
	//TestQ6();
	//TestQ7();
	//TestQ8();
	A120_Triangle		 a120;	a120.runTest();
	A85_MaximalRectangle a85;	a85.runTest();

	cout << "LeetCode --------------------------" << endl;
#endif // TEST_LeetCode


#ifdef TEST_SORT
	cout << "Sort Algorithms --------------------------" << endl;
	CSortAlgo sortAlgo;
	sortAlgo.randon_nums(8);
	sortAlgo.test_sort();
	cout << "Sort Algorithms --------------------------" << endl;
#endif // TEST_SORT

    return 0;
}

#endif