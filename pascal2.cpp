#include<bits/stdc++.h>
using namespace std;
vector<int> getlow(int rowIndex) {
	vector<int> result(rowIndex + 1);
	for (int i = 0; i < result.size(); i++) {
		int prev_res = result[0] = 1;
		for (int j = 1; j <= i; j++) {
			const int temp = result[j];
			result[j] += prev_res;
			prev_res = temp;
		}
	}
	return result;
}
int main() {
	int n;
	cin >> n;
	vector<int> res;
	res = getlow(n);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
}