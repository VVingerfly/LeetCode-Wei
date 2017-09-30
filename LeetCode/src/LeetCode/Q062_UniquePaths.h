
#pragma once
#include <iostream>
#include <vector>
using namespace std;

#ifndef Q062_UniquePaths_h_
#define Q062_UniquePaths_h_


/**
 * @brief 从左上角到右下角只能向下或向右，共有多少种走法？
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 
 * How many possible unique paths are there?

 * @note m and n will be at most 100.
 * @see https://leetcode.com/problems/unique-paths/description/
 */
class A062_UniquePaths
{
public:
	/*! 
	 * @brief Use brief, otherwise the index won't have a brief explanation.
	 *
	 * This is a fundamental DP problem. 
	 * State equations: suppose the number of paths to arrive at a point `(i, j)` is denoted as `P[i][j]`, 
	 * it is easily concluded that **`P[i][j] = P[i - 1][j] + P[i][j - 1]`**.

	 * The boundary conditions of the above equation occur 
	 * at the leftmost column (P[i][j - 1] does not exist) and the uppermost row (P[i - 1][j] does not exist). 
	 * These conditions can be handled by initialization (pre-processing) --- 
	 * initialize P[0][j] = 1, P[i][0] = 1 for all valid i, j. Note the initial value is 1 instead of 0!
	 
	 * @param m number of rows
	 * @param n number pf columns
	 * @return number of unique paths
	 * @note  
	 * @see https://leetcode.com/problems/unique-paths/discuss/
	*/
	int uniquePaths(int m, int n) // runs in O(n^2) time and costs O(m*n) space
	{
		vector<vector<int> > path(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				path[i][j] = path[i - 1][j] + path[i][j - 1];
		return path[m - 1][n - 1];
	}

	int uniquePaths2(int m, int n) // runs in O(n^2) time and costs O(min(m, n)) space
	{
		if (m > n) 
			return uniquePaths2(n, m);
		vector<int> pre(m, 1);
		vector<int> cur(m, 1);
		for (int j = 1; j < n; j++)
		{
			for (int i = 1; i < m; i++)
				cur[i] = cur[i - 1] + pre[i];
			swap(pre, cur);
		}
		return pre[m - 1];
	}



	void runTest()
	{
		cout << uniquePaths(3, 7) << endl;
	}
};


#endif // Q062_UniquePaths_h_