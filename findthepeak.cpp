#include<bits/stdc++.h>
using namespace std;
int findpeak(vector<int>&nums) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] > nums[mid + 1])
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
int main() {
	int n;
	cin >> n;
	vector<int>nums;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << findpeak(nums);
}