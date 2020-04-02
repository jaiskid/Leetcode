#include<bits/stdc++.h>
using namespace std;
int n = 4, m = 5;
vector<vector<char>> matrix = vector<vector<char>>(n, vector<char>(m));


int largest(vector<int>&height) {
	stack<int> increasing_height;
	int max_area = 0;

	for (int i = 0; i <= height.size();) {
		if (increasing_height.empty() ||
		        (i < height.size() && height[i] > height[increasing_height.top()])) {
			increasing_height.emplace(i);
			++i;
		} else {
			auto h = height[increasing_height.top()];
			increasing_height.pop();
			auto left = increasing_height.empty() ? -1 : increasing_height.top();
			max_area = max(max_area, h * (i - left - 1));
		}
	}+

	return max_area;
}
int maximal(vector<vector<char>>&matrix) {
	if (matrix.empty() || matrix[0].empty())
		return 0;
	int res = 0;
	vector<int> height(matrix[0].size(), 0);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
		}
		res = max(res, largest(height));
	}
	return res;
}
int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << maximal(matrix);
}
