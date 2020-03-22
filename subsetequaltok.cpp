#include<bits/stdc++.h>
using namespace std;
int subsetsum(vector<int>&nums, int k) {
	vector<int> sum(nums.size() + 1);
	for (int i = 1; i <= nums.size(); i++) {
		sum[i] = sum[i - 1] + nums[i - 1];
		cout << sum[i] << " ";
	}
	int count = 0;
	for (int start = 0; start < nums.size(); start++) {
		for (int end = start + 1; end <= nums.size(); end++) {
			if (sum[end] - sum[start] == k)
				count++;
		}
	}
	return count;
}
int main() {
	int n;
	cin >> n;
	vector<int> nums;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int k;
	cin >> k;
	cout << subsetsum(nums, k);
}