//#include <iostream>
//using namespace std;
//
//int i = 1;
//int fun(int n)
//{
//	static int a = 2;
//	a++;
//	return a*n;
//}
//
//struct A
//{
//	int a;   // 4 字节
//	char b;  // 1 字节
//	short c; // 2 字节
//};
//struct B
//{
//	char b;  // 1 字节
//	int a;   // 4 字节
//	short c; // 2 字节
//};
//struct Node
//{
//	int a;
//	char * n;
//	//Node *next;
//};
//class C1
//{
//public:
//	C1(){}
//	~C1(){}
//
//private:
//	int a;
//};
//
//
//int main()
//{
//
//	cout << "sizeof(A)     = " <<  sizeof(A) << endl;
//	cout << "sizeof(B)     = " << sizeof(B) << endl;
//	cout << "sizeof(Node)  = " << sizeof(Node) << endl;
//	cout << "sizeof(int*)  = " << sizeof(int*) << endl;
//	cout << "sizeof(int)   = " << sizeof(int) << endl;
//	cout << "sizeof(char*) = " << sizeof(char*) << endl;
//	cout << "sizeof(char)  = " << sizeof(char) << endl;
//
//	cout << "sizeof(C1)    = " << sizeof(C1) << endl;
//
//	int a = 2;
//	 int* const p = &a;
//	*p = 2;
//	return 0;
//
//	int k = 5;
//	{
//		int i = 2;
//
//		cout << fun(i) << endl;
//		k += fun(i);
//
//
//	}
//	cout << fun(i) << endl;
//	k += fun(i);
//	cout << k << endl;
//}




//#include <iostream>
//#include <vector>
//using namespace std;
//
//int findRoots(vector<int> &roots, int id)
//{
//	while (id != roots[id])
//	{
//		roots[id] = roots[roots[id]];
//		id = roots[id];
//	}
//	return id;
//}
//
//void islandCount(int m, int n, vector<pair<int, int>>& positions) 
//{
//	if (m <= 0 || n <= 0) 
//		return;
//
//	vector<int> res;
//	vector<int> roots(m * n, -1);
//	int cnt = 0;
//	vector<vector<int> > dirs{ { 0, -1 },{ -1, 0 },{ 0, 1 },{ 1, 0 } };
//	for (auto a : positions)
//	{
//		int id = n * a.first + a.second;
//		roots[id] = id;
//		++cnt;
//		for (auto d : dirs) 
//		{
//			int x = a.first  + d[0];
//			int y = a.second + d[1];
//			int cur_id = n * x + y;
//			if (x < 0 || x >= m || y < 0 || y >= n || roots[cur_id] == -1) 
//				continue;
//			int new_id = findRoots(roots, cur_id);
//			if (id != new_id) 
//			{
//				roots[id] = new_id;
//				id = new_id;
//				--cnt;
//			}
//		}
//		res.push_back(cnt);
//	}
//
//	// 输出岛屿个数
//	for (int i = 0; i < res.size(); i++)
//		cout << res[i] << ((i == res.size() - 1) ? "\n" : " ");
//}
//
//
//bool getInput(int &m, int &n, vector<pair<int, int>>& positions)
//{
//	int k, i;
//	if (!(cin >> m >> n >> k))
//		return false;
//
//	positions.resize(k);
//	for (i = 0; i < k; i++)
//		if (!(cin >> positions[i].first >> positions[i].second)) 
//			return false;
//	
//	return true;
//}
//
//int main()
//{
//	int m, n;
//	vector<pair<int, int>> positions;
//	while (getInput(m, n, positions))
//	{
//		islandCount(m, n, positions);
//	}
//	return 0;
//}
//// http://www.cnblogs.com/grandyang/p/5190419.html