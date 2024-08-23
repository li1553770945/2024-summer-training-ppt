#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	map<int, vector<int>> a;
	scanf("%d %d", &n, &m);
	for (int i = 1, x, y; i <= m; ++i)
	{
		scanf("%d %d", &x, &y);
		a[x].push_back(y); // map，表示每一行黑兵的y坐标
	}
	set<int> can;
	can.insert(n); // 初始在0，N这个位置，所以能到达的y只有n
	for (auto i : a)
	{
		vector<int> need_del, need_add;
		for (int j : i.second)
			if (can.count(j))
				need_del.push_back(j); // 如果当前黑兵位置的正上方再set里面，现在他不能到达这个位置了，所以需要删除
		for (int j : i.second)
			if (can.count(j - 1) || can.count(j + 1)) // 如果当前黑兵的左上或者右上在set里面，那么他可以到达这个位置，所以需要添加
				need_add.push_back(j);
		for (int j : need_del) 
            can.erase(j);
		for (int j : need_add)
            can.insert(j);
	}
	printf("%d", can.size());
	return 0;
}