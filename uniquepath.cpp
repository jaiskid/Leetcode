#include<bits/stdc++.h>
using namespace std;
int minimumpath(int n, int m) {
	if (m > n)
		swap(m, n);
	if (m < 2)
		return m;
	vector<int> steps(n, 1);
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			steps[j] += steps[j - 1];
		}
	}
	return steps[n - 1];
}
int main() {
	int n, m;
	cin >> n >> m;
	cout << minimumpath(n, m);
}