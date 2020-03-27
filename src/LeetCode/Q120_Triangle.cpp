#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Find the minimum path sum from top to bottom of a triangle.
 *
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 * For example, given the following triangle \n
 ```
 [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
 ]
 ```
 The minimum path sum from top to bottom is `11` (i.e., `2 + 3 + 5 + 1 = 11`).
 * @note Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 * @see https://leetcode.com/problems/triangle/description/
 */
class A120_Triangle
{
public:
#define min(x, y) ((x < y) ? (x) : (y))
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        vector<int> minlen(triangle.back());
        for (int layer = n - 2; layer >= 0; layer--)  // For each layer
        {
            for (int i = 0; i <= layer; i++)  // Check its every 'node'
            {
                // Find the lesser of its two children, and sum the current value in the triangle with it.
                minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
            }
        }
        return minlen[0];
    }

    void runTest()
    {
        vector<vector<int>> triangle(4);
        triangle[0] = vector<int>{ 2 };
        triangle[1] = vector<int>{ 3, 4 };
        triangle[2] = vector<int>{ 6, 5, 7 };
        triangle[3] = vector<int>{ 4, 1, 8, 3 };
        cout << minimumTotal(triangle) << endl;
    }
};
