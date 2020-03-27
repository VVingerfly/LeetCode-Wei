#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Find the largest rectangle and return its area.
 *
 * Given a 2D binary matrix filled with 0's and 1's,
 * find the largest rectangle containing only 1's and return its area.
 * For example, given the following matrix:
 ```
 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0
 ```
 Return 6.
 * @see https://leetcode.com/problems/maximal-rectangle/description/
*/
class A85_MaximalRectangle
{
public:
#define max(x, y) ((x < y) ? (y) : (x))
#define min(x, y) ((x < y) ? (x) : (y))

    /*!
     * @brief DP solution.
     *
     * The DP solution proceeds row by row, starting from the first row.
     * Let the maximal rectangle area at row i and column j be computed by [right(i,j) - left(i,j)]*height(i,j).
     * All the 3 variables left, right, and height can be determined by the information from previous row,
     * and also information from the current row. So it can be regarded as a DP solution. The transition equations are:
     * ```
     * left(i,j) = max(left(i-1,j), cur_left), cur_left can be determined from the current row
     * right(i,j) = min(right(i-1,j), cur_right), cur_right can be determined from the current row
     * height(i,j) = height(i-1,j) + 1, if matrix[i][j]=='1';
     * height(i,j) = 0, if matrix[i][j]=='0'
     * ```
     * @param matrix input rectangle
     * @return maximal area of rectangle
     * @note  If you think this algorithm is not easy to understand, you can try this example:
     * ```
     * 0 0 0 1 0 0 0
     * 0 0 1 1 1 0 0
     * 0 1 1 1 1 1 0
     * ```
     * The vector "left" and "right" from row 0 to row 2 are as follows
     * row 0:
     * ```
     * l: 0 0 0 3 0 0 0
     * r: 7 7 7 4 7 7 7
     * ```
     * row 1:
     * ```
     * l: 0 0 2 3 2 0 0
     * r: 7 7 5 4 5 7 7
     * ```
     * row 2:
     * ```cpp
     * l: 0 1 2 3 2 1 0
     * r: 7 6 5 4 5 6 7
     * ```
     * The vector "left" is computing the left boundary. Take (i,j)=(1,3) for example.
     * On current row 1, the left boundary is at j=2.
     * However, because matrix[1][3] is 1, you need to consider the left boundary on previous row as well, which is 3.
     * So the real left boundary at (1,3) is 3.
     * @see https://discuss.leetcode.com/topic/6650/share-my-dp-solution/2
     */
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        if (matrix.empty())
            return 0;
        const int m = matrix.size();     // rows
        const int n = matrix[0].size();  // cols
        int* left = new int[n];
        int* right = new int[n];
        int* height = new int[n];
        fill_n(left, n, 0);
        fill_n(right, n, n);
        fill_n(height, n, 0);
        int maxA = 0;
        for (int i = 0; i < m; i++)  // for each row
        {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; j++) {
                // compute height (can do this from either side)
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            for (int j = 0; j < n; j++) {
                // compute left (from left to right)
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], cur_left);
                else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                // compute right (from right to left)
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], cur_right);
                else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            // compute the area of rectangle (can do this from either side)
            for (int j = 0; j < n; j++)
                maxA = max(maxA, (right[j] - left[j]) * height[j]);
        }
        delete[] left;
        delete[] right;
        delete[] height;
        return maxA;
    }

    void runTest()
    {
        vector<vector<char>> matrix(4);
        matrix[0] = vector<char>{ '1', '0', '1', '0', '0' };
        matrix[1] = vector<char>{ '1', '0', '1', '1', '1' };
        matrix[2] = vector<char>{ '1', '1', '1', '1', '1' };
        matrix[3] = vector<char>{ '1', '0', '0', '1', '0' };
        cout << maximalRectangle(matrix) << endl;
    }
    void runTest2()
    {
        vector<vector<char>> matrix(3);
        matrix[0] = vector<char>{ '0', '0', '0', '1', '0', '0', '0' };
        matrix[1] = vector<char>{ '0', '0', '1', '1', '1', '0', '0' };
        matrix[2] = vector<char>{ '1', '1', '1', '1', '1', '1', '1' };
        cout << maximalRectangle(matrix) << endl;
    }
};
