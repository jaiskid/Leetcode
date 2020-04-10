#include<bits/stdc++.h>
using namespace std;
bool canFinish(int n, vector<vector<int>>& prerequisites) {
	vector<vector<int>> g(n, vector<int>());
	vector<int> d(n, 0);
	queue<int> que;
	for (auto e : prerequisites) {
		g[e[1]].emplace_back(e[0]);
		d[e[0]]++;
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] == 0) {
			res++;
			que.push(i);
		}
	}
	while (!que.empty() and (res <= n)) {
		int i = que.front();
		que.pop();
		for (auto x : g[i]) {
			if (--d[x] == 0) {
				que.push(x);
				res++;
			}
		}
	}
	return (que.empty() and (res == n));
}