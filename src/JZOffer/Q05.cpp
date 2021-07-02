#include <vector>
#include <string>

using std::string;

/**
 * @brief 
 * 
 * @ note https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
 */
class A05 {
public:
    string replaceSpace(string s) {
        string str;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') str += "%20";
            else str += s[i];
        }
        return str;
    }
};
