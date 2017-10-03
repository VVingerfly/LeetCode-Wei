//#include<iostream>
//
//
//
//
//using namespace std;
//
//#define maxlen 50
//#define maxresult 100000000
//int x[maxlen], y[maxlen];
//int ans[maxlen];
//int result[maxlen];
//int n, dst_x, dst_y;
//int tmp;
//#define ABS(a) ((a)<0?-(a):(a))
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//		cin >> x[i];
//	for (int i = 0; i < n; ++i)
//		cin >> y[i];
//	
//	for (int i = 0; i < n; ++i)
//	{
//		result[i] = maxresult;
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			dst_x = x[i]; dst_y = y[j];
//
//			for (int k = 0; k < n; ++k)
//			{
//				ans[k] = maxresult;
//			}
//			for (int k = 0; k < n; ++k)
//			{
//				tmp = abs(dst_x - x[k]) + abs(dst_y - y[k]);
//				int m = 0;
//				for (m = 0; m < k; ++m)
//				{
//					if (tmp < ans[m])
//					{
//						break;
//					}
//				}
//				for (int h = k; h > m; --h)
//				{
//					ans[h] = ans[h - 1];
//				}
//				ans[m] = tmp;
//			}
//			for (int k = 1; k < n; ++k)
//			{
//				ans[k] += ans[k - 1];
//			}
//			for (int k = 0; k < n; ++k)
//			{
//				if (result[k] < ans[k])
//				{
//					result[k] = ans[k];
//				}
//			}
//		}
//	}
//	for (int i = 0; i < n - 1; ++i)
//	{
//		cout << ans[i] << '\t';
//	}
//	cout << ans[n - 1] << endl;
//
//	cin >> n;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
////#include <iostream>
////#include <string>
////#include <vector>
////
////using namespace std;
////
////int main()
////{
////	typedef  long long LInt;
////	int n;
////	//cin >> n;
////	n = 4;
////	LInt * xCoord = new LInt[n];
////	LInt * yCoord = new LInt[n];
////	//for (int i = 0; i < n; i++) cin >> xCoord[i];
////	//for (int i = 0; i < n; i++) cin >> yCoord[i];
////	xCoord[0] = 1; xCoord[1] = 2; xCoord[2] = 4; xCoord[3] = 9;
////	yCoord[0] = 1; yCoord[1] = 1; yCoord[2] = 1; yCoord[3] = 1;
////
////	LInt xMin, xMax, yMin, yMax;
////	xMax = -1; yMax = -1;
////	xMin = 10e9; yMin = 10e9;
////	cout << xMin << " " << yMin << endl;
////	for (int i = 0; i < n; i++)
////	{
////		if (xCoord[i] < xMin) xMin = xCoord[i];
////		if (xCoord[i] > xMax) xMax = xCoord[i];
////		if (yCoord[i] < yMin) yMin = yCoord[i];
////		if (yCoord[i] > yMax) yMax = yCoord[i];
////	}
////	cout << "min " << xMin << " " << yMin << endl;
////	cout << "max " << xMax << " " << yMax << endl;
////
////	LInt xCnt = xMax - xMin + 1;
////	LInt yCnt = yMax - yMin + 1;
////	cout << "cnt " << xCnt << " " << yCnt << endl;
////
////	typedef  vector<vector<int>> grid;
////	vector<grid> steps4Pos; // steps for each position for each point
////	steps4Pos.resize(n);
////
////	
////	return 0;
////}
