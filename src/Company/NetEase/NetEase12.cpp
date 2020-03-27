
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/**
 * @brief 字符迷阵，在给定的矩形的字符迷阵中寻找特定的单词. (还有问题）
 *
 * 字符迷阵是一种经典的智力游戏。玩家需要在给定的矩形的字符迷阵中寻找特定的单词。
 * 在这题的规则中，单词是如下规定的：
 * 1. 在字符迷阵中选取一个字符作为单词的开头；
 * 2. 选取右方、下方、或右下45度方向作为单词的延伸方向；
 * 3. 以开头的字符，以选定的延伸方向，把连续得到的若干字符拼接在一起，则称为一个单词。
 *
 *
 * 以图1为例，如果要在其中寻找单词"WORD"，则绿色框所标示的都是合法的方案，而红色框所标示的都是不合法的方案。
 * 现在的问题是，给出一个字符迷阵，及一个要寻找的单词，问能在字符迷阵中找到多少个该单词的合法方案。注意合法方案是可以重叠的，如图1所示的字符迷阵，其中单词"WORD"的合法方案有4种。
 *
 * **输入描述:**
 * 输入的第一行为一个正整数T，表示测试数据组数。
 接下来有T组数据。每组数据的第一行包括两个整数m和n，表示字符迷阵的行数和列数。接下来有m行，每一行为一个长度为n的字符串，按顺序表示每一行之中的字符。再接下来还有一行包括一个字符串，表示要寻找的单词。
 数据范围： 对于所有数据，都满足1<=T<=9，且输入的所有位于字符迷阵和单词中的字符都为大写字母。要寻找的单词最短为2个字符，最长为9个字符。字符迷阵和行列数，最小为1，最多为99。
 对于其中50%的数据文件，字符迷阵的行列数更限制为最多为20。

 * **输出描述:**
 * 对于每一组数据，输出一行，包含一个整数，为在给定的字符迷阵中找到给定的单词的合法方案数。

 * **示例1**

 * 输入
 * ```
 * 3
 * 10 10
 * AAAAAADROW
 * WORDBBBBBB
 * OCCCWCCCCC
 * RFFFFOFFFF
 * DHHHHHRHHH
 * ZWZVVVVDID
 * ZOZVXXDKIR
 * ZRZVXRXKIO
 * ZDZVOXXKIW
 * ZZZWXXXKIK
 * WORD
 * 3 3
 * AAA
 * AAA
 * AAA
 * AA
 * 5 8
 * WORDSWOR
 * ORDSWORD
 * RDSWORDS
 * DSWORDSW
 * SWORDSWO
 * SWORD
 * ```
 * 输出
 * ```
 * 4
 * 16
 * 5
 * ```
 * @note
 * @see
 */
class CNetEase12
{
public:
    int validWordCount(string word, vector<string> wordMat)
    {
        int cnt = 0;
        cnt += searchRow(word, wordMat);
        cnt += searchCol(word, wordMat);
        cnt += searchDiag(word, wordMat);

        cout << "row  = " << searchRow(word, wordMat) << endl;
        cout << "col  = " << searchCol(word, wordMat) << endl;
        cout << "diag = " << searchDiag(word, wordMat) << endl;
        return cnt;
    }


    int subStrCount(string str, string substr)
    {
        int index = -1;
        int count = 0;
        while (index = str.find(substr, index + 1), index != string::npos) {
            count++;
        }
        return count;
    }

    int searchRow(string word, const vector<string>& wordMat)
    {
        int cnt = 0;
        for (int i = 0; i < wordMat.size(); i++)
            cnt += subStrCount(wordMat.at(i), word);
        return cnt;
    }

    int searchCol(string word, const vector<string>& wordMat)
    {
        int cnt = 0;
        int m = wordMat.size();
        int n = wordMat.at(0).length();
        for (int c = 0; c < n; c++) {
            string str;
            for (int r = 0; r < m; r++)
                str += wordMat.at(r).at(c);
            cnt += subStrCount(str, word);
        }
        return cnt;
    }

    int searchDiag(string word, const vector<string>& wordMat)
    {
        int cnt = 0;
        int m = wordMat.size();
        int n = wordMat.at(0).length();
        int s = word.length();
        for (int i = 0; i < n; i++) {
            cout << i << " = ";
            if (i == 0) {
                string str;
                for (int j = 0; j < m && j < n; j++)
                    str += wordMat.at(j).at(j);
                cnt += subStrCount(str, word);
                cout << str << endl;
                continue;
            }
            string strUp, strDn;
            for (int j = i; j < m && j < n; j++) {
                strUp += wordMat.at(j - 1).at(j);
                strDn += wordMat.at(j).at(j - 1);
            }
            cout << strUp << "  &  ";
            cout << strDn << endl;
            cnt += subStrCount(strUp, word);
            cnt += subStrCount(strDn, word);
        }
        return cnt;
    }


    void runTest1()
    {
        vector<string> wordMat;
        wordMat.push_back("WORDSWOR");
        wordMat.push_back("ORDSWORD");
        wordMat.push_back("RDSWORDS");
        wordMat.push_back("DSWORDSW");
        wordMat.push_back("SWORDSWO");

        string word = "SWORD";
        cout << "target word = " << word << endl;
        cout << "my res = " << validWordCount(word, wordMat) << endl;
        cout << "actual = 5" << endl << endl;
    }

    void runTest2()
    {
        vector<string> wordMat;
        wordMat.push_back("AAA");
        wordMat.push_back("AAA");
        wordMat.push_back("AAA");

        string word = "AA";
        cout << "target word = " << word << endl;
        cout << "my res = " << validWordCount(word, wordMat) << endl;
        cout << "actual = 16" << endl << endl;
    }

    void runTest3()
    {
        vector<string> wordMat;
        wordMat.push_back("AAAAAADROW");
        wordMat.push_back("WORDBBBBBB");
        wordMat.push_back("OCCCWCCCCC");
        wordMat.push_back("RFFFFOFFFF");
        wordMat.push_back("DHHHHHRHHH");
        wordMat.push_back("ZWZVVVVDID");
        wordMat.push_back("ZOZVXXDKIR");
        wordMat.push_back("ZRZVXRXKIO");
        wordMat.push_back("ZDZVOXXKIW");
        wordMat.push_back("ZZZWXXXKIK");

        string word = "WORD";
        cout << "target word = " << word << endl;
        cout << "my res = " << validWordCount(word, wordMat) << endl;
        cout << "actual = 4" << endl << endl;
    }

    void testFind()
    {
        string word = "SWORD";
        string s1 = "SWORDSWO";
        string s2 = "SWOORDSWO";
        string s3 = "QQSWORDSWO";

        string::size_type pos;

        pos = s1.find(word);
        if (pos != s1.npos) {
            cout << "S1 position is : " << pos << endl;
        }
        pos = s2.find(word);
        if (pos != s2.npos) {
            cout << "S2 position is : " << pos << endl;
        }
        pos = s3.find(word);
        if (pos != s3.npos) {
            cout << "S3 position is : " << pos << endl;
        }
    }

    void testCnt()
    {
        string word = "AA";
        string s1 = "AAABABAABAAA";
        string s2 = "SWOORDSWO";
        string s3 = "QQSWORDSWO";
        int index = -1;
        int count = 0;
        while (index = s1.find(word, index + 1), index != string::npos) {
            count++;
        }
        cout << count << endl;
    }
};

int main()
{
    CNetEase12 netease12;
#if 1
    netease12.runTest1();
    netease12.runTest2();
    netease12.runTest3();
#else

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int m, n;
        cin >> m >> n;
        vector<string> wordMat;
        for (int i = 0; i < m; i++) {
            string str;
            cin >> str;
            wordMat.push_back(str);
        }
        string word;
        cin >> word;
        cout << netease12.validWordCount(word, wordMat) << endl;
    }
#endif
    return 0;
}
