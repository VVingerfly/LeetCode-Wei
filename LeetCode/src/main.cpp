#include <iostream>
#include "LeetCode.h"
#include "../src/Sort/sort_algo.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
	//TestQ3();
	//TestQ4();
	//TestQ5();
	//TestQ6();
	//TestQ7();
	//TestQ8();


	CSortAlgo sortAlgo;
	sortAlgo.randon_nums(8);
	sortAlgo.test_sort();
    return 0;
}
