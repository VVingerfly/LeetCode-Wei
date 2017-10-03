#include "sort_algo.h"
#include "../global.h"
#include <iostream>
using namespace std;


#ifdef RUN_Sort
int main()
{
	cout << "Sort Algorithms --------------------------" << endl;
	CSortAlgo sortAlgo;
	sortAlgo.randon_nums(8);
	sortAlgo.test_sort();
    return 0;
}

#endif // RUN_Sort