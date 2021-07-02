/**
 * @file Q17_LetterCombinationsOfPhoneNumber.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 电话号码的字母组合
 * @version 0.1
 * @date 2021-01-31
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 电话号码的字母组合
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 * 示例 1：
 * - 输入：digits = "23"
 * - 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 * 示例 2：
 * - 输入：digits = ""
 * - 输出：[]
 *
 * 示例 3：
 * - 输入：digits = "2"
 * - 输出：["a","b","c"]
 *
 * 提示：
 * - `0 <= digits.length <= 4`
 * - `digits[i]` 是范围 ['2', '9'] 的一个数字。
 *
 * @note https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
 */
class A17_LetterCombinationsOfPhoneNumber
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> results;
        if (digits.empty())
            return results;

        auto letters = unordered_map<char, string>{ { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };

        string letter;
        dfs(letters, digits, 0, results, letter);
        // bfs(letters, digits, results);

        return results;
    }

    // 深度优先搜索（递归/回溯）
    void dfs(const unordered_map<char, string>& letters, const string& digits, int index, vector<string>& results, string& letter)
    {
        if (index == digits.length()) {
            results.push_back(letter);
            return;
        }

        char dig = digits[index];
        const string& str = letters.at(dig);
        for (const auto& c : str) {
            letter.push_back(c);
            dfs(letters, digits, index + 1, results, letter);  //递归调用
            letter.pop_back();
        }
    }

    // 广度优先搜索
    void bfs(const unordered_map<char, string>& letters, const string& digits, vector<string>& results)
    {
        queue<string> workQueue;
        workQueue.push("");
        for (const auto& targetChar : digits) {
            string targetStr = letters.at(targetChar);
            int queueSize = int(workQueue.size());
            //当前层，进行添加字符
            for (int i = 0; i < queueSize; ++i) {
                string tmpStr = workQueue.front();
                workQueue.pop();
                for (const auto& tmpChar : targetStr) {
                    workQueue.push(tmpStr + tmpChar);
                }
            }
        }
        while (!workQueue.empty()) {
            string tmpStr = workQueue.front();
            workQueue.pop();
            results.push_back(tmpStr);
        }
    }

};

int main()
{
    vector<string> digits = { "23", "", "2" };
    vector<vector<string>> solutions = { { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }, {}, { "a", "b", "c" } };
    auto is_equal = [](const vector<string>& solution, const vector<string>& result) {
        if (solution.size() != result.size())
            return false;

        auto sol = solution;
        auto res = result;
        sort(sol.begin(), sol.end());
        sort(res.begin(), res.end());
        for (size_t i = 0; i < sol.size(); i++) {
            if (sol[i] != res[i])
                return false;
        }
        return true;
    };

    A17_LetterCombinationsOfPhoneNumber a17;
    for (size_t i = 0; i < digits.size(); i++) {
        auto res = a17.letterCombinations(digits[i]);
        if (is_equal(solutions[i], res))
            cout << "Pass" << endl;
        else {
            cout << "Fail" << endl;
            cout << "  Returned Result: ";
            for (const auto& s : res)
                cout << " " << s;
            cout << endl;
            cout << "  Expected Result: ";
            for (const auto& s : solutions[i])
                cout << " " << s;
            cout << endl;
        }
    }
    return 0;
}
