#include<bits/stdc++.h>
using namespace std;
int longestin(int *nums, int n) {
	int dp[n] = {1};
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(res, dp[i]);
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	cout << longestin(nums, n);
}