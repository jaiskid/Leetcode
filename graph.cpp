#include<bits/stdc++.h>
using namespace std;
int main() {
	int i, n, m;
	cin >> n >> m;
	//n is for vertices
	//m is for edges
	vector<int> gr[n + 1];
	for (i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
	}
	for (int i = 0; i < gr.size(); i++)
		cout << gr[i] << " ";
}