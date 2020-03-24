#include<bits/stdc++.h>
using namespace std;
int jump(vector<int>& nums) {
	int step = 0, maxi = 0;
	for (int i = 0, tempmax = 0; i <= maxi and i < nums.size() - 1 ; i++) {
		tempmax = max(tempmax, nums[i] + i);
		if (i == maxi)
			maxi = tempmax, ++step;
	}
	return maxi >= (nums.size() - 1) ? step : -1;
}
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << jump(nums) << endl;
}