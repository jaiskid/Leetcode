#include<bits/stdc++.h>
using namespace std;
int subarraysum(int *nums, int n) {
	int sum[n + 1];
	sum[0] = nums[0];
	int maxi = INT_MIN;
	for (int i = 1; i < n + 1; i++) {
		sum[i] = max(sum[i - 1] + nums[i], nums[i]);
		maxi = max(sum[i], maxi);
	}
	return maxi;
}
int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	cout << subarraysum(nums, n);

}