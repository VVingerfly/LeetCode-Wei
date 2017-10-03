////#include <iostream>
////#include <vector>
////using namespace std;
////
////class UnionFind2D 
////{
////public:
////	UnionFind2D(int m, int n) {
////		for (int i = 0; i < m * n; i++) ids.push_back(-1);
////		for (int i = 0; i < m * n; i++) szs.push_back(1);
////		M = m, N = n, cnt = 0;
////	}
////	int index(int x, int y) {
////		return x * N + y;
////	}
////	int size(void) {
////		return cnt;
////	}
////	int id(int x, int y) {
////		if (x >= 0 && x < M && y >= 0 && y < N)
////			return ids[index(x, y)];
////		return -1;
////	}
////	int add(int x, int y) {
////		int idx = index(x, y);
////		ids[idx] = idx;
////		szs[idx] = 1;
////		cnt++;
////		return idx;
////	}
////	int root(int i) {
////		for (; i != ids[i]; i = ids[i])
////			ids[i] = ids[ids[i]];
////		return i;
////	}
////	bool find(int p, int q) {
////		return root(p) == root(q);
////	}
////	void unite(int p, int q) {
////		int i = root(p), j = root(q);
////		if (szs[i] > szs[j]) swap(i, j);
////		ids[i] = j;
////		szs[j] += szs[i];
////		cnt--;
////	}
////private:
////	vector<int> ids, szs;
////	int M, N, cnt;
////};
////
////
////void numIslands2(int m, int n, vector<pair<int, int>>& positions) 
////{
////	UnionFind2D islands(m, n);
////	vector<pair<int, int>> dirs = { { 0, -1 },{ 0, 1 },{ -1, 0 },{ 1, 0 } };
////	vector<int> ans;
////	for (auto& pos : positions) 
////	{
////		int x = pos.first, y = pos.second;
////		int p = islands.add(x, y);
////		for (auto& d : dirs) {
////			int q = islands.id(x + d.first, y + d.second);
////			if (q >= 0 && !islands.find(p, q))
////				islands.unite(p, q);
////		}
////		ans.push_back(islands.size());
////	}
////	for (int i = 0; i < ans.size(); i++)
////	{
////		cout << ans[i];
////		if (i == ans.size() - 1) cout << endl;
////		else cout << " ";
////	}
////}
////
////bool getInput(int &m, int &n, vector<pair<int, int>>& positions)
////{
////	int k, i;
////	bool flag = true;
////	if (!(cin >> m >> n >> k)) 
////		flag = false;
////
////	positions.resize(k);
////	for (i = 0; i < k; i++)
////	{
////		if (!(cin >> positions[i].first >> positions[i].second)) flag = false;
////	}
////	return flag;
////}
////
////int main()
////{
////	int m, n;
////	vector<pair<int, int>> positions;
////	while (getInput(m, n, positions))
////	{
////		numIslands2(m, n, positions);
////	}
////	return 0;
////}

//http://www.cnblogs.com/jcliBlogger/p/4965051.html