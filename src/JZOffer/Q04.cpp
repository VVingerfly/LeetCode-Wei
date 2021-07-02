#include <vector>

using std::vector;


/**
 * @brief 
 * 
 * @note https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 */
class A04 {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int col = search_row(matrix, target, 0);
        if (col == -1)
            return true;
        for (int c = 0; c < col; ++c){
            int row = search_col(matrix, target, c);
            if (col == -1)
                return true;
        }
        return false;
    }
    int search_row(vector<vector<int>>& matrix, int target, int row)
    {
        int num = matrix[row].size();
        int left = 0, right = num - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] == target)
                return -1;
            else if (matrix[row][mid] < target)
                left = mid;
            else
                right = mid;
        }
        return left;
    }
    int search_col(vector<vector<int>>& matrix, int target, int col)
    {
        int num = matrix.size();
        int left = 0, right = num - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[mid][col] == target)
                return -1;
            else if (matrix[mid][col] < target)
                left = mid;
            else
                right = mid;
        }
        return left;
    }
};
