//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	string s;
//	cin >> s;
//	//s = "10101";
//	int maxLen = 0;
//	int len = s.length();
//	string curr_char, next_char;
//	for (int i = 0; i < len; i++)
//	{
//		curr_char = s.at(i);
//		for (int j = i + 1; j < len; j++)
//		{
//			next_char = s.at(j);
//			if (curr_char == next_char )
//			{
//				if (j - i > maxLen)
//					maxLen = j - i;
//				break;
//			}
//			else
//				curr_char = next_char;
//
//			if (j == len - 1)
//			{
//				if (j - i > maxLen)
//					maxLen = j + 1 - i;
//				break;
//			}
//		}
//		
//	}
//	cout << maxLen << endl;
//	return 0;
//}


