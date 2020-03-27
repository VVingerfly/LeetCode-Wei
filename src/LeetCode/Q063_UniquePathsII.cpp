#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief How many possible unique paths are there?
 *
 * Follow up for "Unique Paths":
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.

 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * ```
 * [
 * 	  [0,0,0],
 * 	  [0,1,0],
 * 	  [0,0,0]
 * ]
 * ```
 * The total number of unique paths is 2.

 * @note m and n will be at most 100.
 * @see https://leetcode.com/problems/unique-paths-ii/description/
 */
class A063_UniquePathsII
{
public:
    /*!
     * @brief just use dp to find the answer , if there is a obstacle at (i,j), then dp[i][j] = 0.
     *
     * this problem is similar to Unique Paths.
     * The introduction of obstacles only changes the boundary conditions and make some points unreachable (simply set to 0).

     * Denote the number of paths to arrive at point (i, j) to be P[i][j],
     * the state equation is P[i][j] = P[i - 1][j] + P[i][j - 1] if obstacleGrid[i][j] != 1 and 0 otherwise.

     * Now let's finish the boundary conditions.
     * In the Unique Paths problem, we initialize P[0][j] = 1, P[i][0] = 1 for all valid i, j.
     * Now, due to obstacles, some boundary points are no longer reachable and need to be initialized to 0.
     * For example, if obstacleGrid is like `[0, 0, 1, 0, 0]`, then the last three points are not reachable and need to be initialized to be 0.
     * The result is `[1, 1, 0, 0, 0]`.

     * Now we can write down the following (unoptimized) code.
     * Note that we pad the obstacleGrid by 1 and initialize dp[0][1] = 1 to unify the boundary cases.

     * @param obstacleGrid An obstacle and empty space is marked as 1 and 0 respectively in the grid.
     * @return  number of unique paths
     * @note  time is O(nm) , space is O(nm) .
     * @see https://leetcode.com/problems/unique-paths-ii/discuss/
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }

    void runTest()
    {
        vector<vector<int>> mat(3);
        mat[0] = vector<int>{ 0, 0, 0 };
        mat[1] = vector<int>{ 0, 1, 0 };
        mat[2] = vector<int>{ 0, 0, 0 };
        cout << uniquePathsWithObstacles(mat) << endl;
    }
};
