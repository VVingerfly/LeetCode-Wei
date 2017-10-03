
#include "NetEaseDefs.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


/**
 * @brief �ַ������ڸ����ľ��ε��ַ�������Ѱ���ض��ĵ���. (�������⣩
 *
 * �ַ�������һ�־����������Ϸ�������Ҫ�ڸ����ľ��ε��ַ�������Ѱ���ض��ĵ��ʡ�
 * ������Ĺ����У����������¹涨�ģ�
 * 1. ���ַ�������ѡȡһ���ַ���Ϊ���ʵĿ�ͷ��
 * 2. ѡȡ�ҷ����·���������45�ȷ�����Ϊ���ʵ����췽��
 * 3. �Կ�ͷ���ַ�����ѡ�������췽�򣬰������õ��������ַ�ƴ����һ�����Ϊһ�����ʡ�
 *
 *
 * ��ͼ1Ϊ�������Ҫ������Ѱ�ҵ���"WORD"������ɫ������ʾ�Ķ��ǺϷ��ķ���������ɫ������ʾ�Ķ��ǲ��Ϸ��ķ�����
 * ���ڵ������ǣ�����һ���ַ����󣬼�һ��ҪѰ�ҵĵ��ʣ��������ַ��������ҵ����ٸ��õ��ʵĺϷ�������ע��Ϸ������ǿ����ص��ģ���ͼ1��ʾ���ַ��������е���"WORD"�ĺϷ�������4�֡�
 *
 * **��������:**
 * ����ĵ�һ��Ϊһ��������T����ʾ�������������� ��������T�����ݡ�ÿ�����ݵĵ�һ�а�����������m��n����ʾ�ַ��������������������������m�У�ÿһ��Ϊһ������Ϊn���ַ�������˳���ʾÿһ��֮�е��ַ����ٽ���������һ�а���һ���ַ�������ʾҪѰ�ҵĵ��ʡ�  ���ݷ�Χ�� �����������ݣ�������1<=T<=9�������������λ���ַ�����͵����е��ַ���Ϊ��д��ĸ��ҪѰ�ҵĵ������Ϊ2���ַ����Ϊ9���ַ����ַ����������������СΪ1�����Ϊ99�� ��������50%�������ļ����ַ������������������Ϊ���Ϊ20��
 
 * **�������:**
 * ����ÿһ�����ݣ����һ�У�����һ��������Ϊ�ڸ������ַ��������ҵ������ĵ��ʵĺϷ���������
 
 * **ʾ��1**  
 
 * ����
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
 * ���
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
		while (index = str.find(substr, index + 1), index != string::npos)
		{
			count++;
		}
		return count;
	}

	int searchRow(string word, const vector<string> &wordMat)
	{
		int cnt = 0;
		for (int i = 0; i < wordMat.size(); i++)
			cnt += subStrCount(wordMat.at(i), word);
		return cnt;
	}

	int searchCol(string word, const vector<string> &wordMat)
	{
		int cnt = 0;
		int m = wordMat.size();
		int n = wordMat.at(0).length();
		for (int c = 0; c < n; c++)
		{
			string str;
			for (int r = 0; r < m; r++)
				str += wordMat.at(r).at(c);
			cnt += subStrCount(str, word);
		}
		return cnt;
	}

	int searchDiag(string word, const vector<string> &wordMat)
	{
		int cnt = 0;
		int m = wordMat.size();
		int n = wordMat.at(0).length();
		int s = word.length();
		for (int i = 0; i < n; i++)
		{
			cout << i << " = ";
			if (i == 0)
			{
				string str;
				for (int j = 0; j < m && j < n; j++)
					str += wordMat.at(j).at(j);
				cnt += subStrCount(str, word);
				cout << str << endl;
				continue;
			}
			string strUp, strDn;
			for (int j = i; j < m && j < n; j++)
			{
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
		if (pos != s1.npos)
		{
			cout << "S1 position is : " << pos << endl;
		}
		pos = s2.find(word);
		if (pos != s2.npos)
		{
			cout << "S2 position is : " << pos << endl;
		}
		pos = s3.find(word);
		if (pos != s3.npos)
		{
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
		while (index = s1.find(word, index + 1), index != string::npos)
		{
			count++;
		}
		cout << count << endl;
	}

};



#ifdef RUN_NetEase12



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
	for (int t = 0; t < T; t++)
	{
		int m, n;
		cin >> m >> n;
		vector<string> wordMat;
		for (int i = 0; i < m; i++)
		{
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

#endif




