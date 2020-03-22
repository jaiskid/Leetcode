#include<bits/stdc++.h>
using namespace std;
int maxpath(vector<vector<int>>&grid) {
	for (decltype(grid.size()) i = 0 ; i < grid.size(); i++) {
		for (decltype(grid[0].size()) j = 0; j < grid[0].size(); j++) {
			if (i == 0 and j == 0)
				continue;
			else if (i == 0)
				grid[i][j] += grid[i][j - 1];
			else if (j == 0)
				grid[i][j] += grid[i - 1][j];
			else
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
		}
	}
	return grid.back().back();
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>grid = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << maxpath(grid);
}