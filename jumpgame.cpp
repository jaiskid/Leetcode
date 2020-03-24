#include<bits/stdc++.h>
using namespace std;
bool maximum(vector<int>nums) {
	for (int i = 0, maxi = 0; i <= maxi; i++) {
		if ((maxi = max(maxi, nums[i] + i) >= nums.size() - 1))
			return true;
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	vector<int> nums;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << maximum(nums) << endl;
}