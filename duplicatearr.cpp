#include<bits/stdc++.h>
using namespace std;
vector<int> duplicate(vector<int> &nums) {
	vector<int> res;
	for (const auto & i : nums) {
		if (nums[abs(i) - 1] < 0) {
			res.emplace_back(abs(i));
		}
		else {
			nums[abs(i) - 1] *= -1;
		}
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<int> res = duplicate(nums);
	for (int i = 0; i < res.nums(); ++i) {
		cout << res[i] << " ";
	}
}