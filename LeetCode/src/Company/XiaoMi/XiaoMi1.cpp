
#include "XiaoMiDefs.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief ����ģʽƥ��
 *
 * **��Ŀ������**\n
 * �����ı�text�ʹ�ƥ���ַ���pattern�����߽�ֻ����Сд��ĸ�����Ҳ�Ϊ�ա�
 * ��text���ҳ�ƥ��pattern������ַ�����ƥ��ָ�������pattern������Ҫ��pattern������
 * ��textΪabaacxbcbbbbacc��patternΪcbc��text��������������abaacxbcbbbbacc��ɫ���֡�

 * **����**\n
 * ÿ��һ��text��һ��pattern���ÿո�ָ�
 *
 * **���**\n
 * ������ƥ��������ֹλ�ã��ÿո�ָ����������������Ĵ𰸣�����ֹ��Ϊ-1

 * **��������**
 * ```
 * abaacxbcbbbbacc cbc
 * abc x
 * aaabcac ac
 * ```
 * **�������**
 * ```
 * 4 7
 * -1 -1
 * 5 6
 * ```
 * @note To be finished.
 * @see 
 */
class XiaoMi1
{
public:
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


	void runTest()
	{

	}
};


#ifdef RUN_XiaoMi1

int main()
{
	XiaoMi1 mi1;
	mi1.runTest();
	return 0;
}

#endif // RUN_XiaoMi1