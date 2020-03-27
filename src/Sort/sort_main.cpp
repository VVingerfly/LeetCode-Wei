#include <iostream>
#include "sort_algo.h"
using namespace std;


int main()
{
    cout << "Sort Algorithms --------------------------" << endl;
    CSortAlgo sortAlgo;
    sortAlgo.randon_nums(8);
    sortAlgo.test_sort();
    return 0;
}
