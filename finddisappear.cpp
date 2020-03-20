#include<bits/stdc++.h>
using namespace std;
vector<int> findDisappered(vector<int>&nums) {
	for (const auto &i : nums) {
		if (nums[abs(i) - 1] > 0) {
			nums[abs(i) - 1] *= -1;
		}
	}
	vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0) {
			result.emplace_back(i + 1);
		}
		else {
			nums[i] *= i;
		}
	}
	return result;
}
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<int> res;
	res = findDisappered(nums);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
}