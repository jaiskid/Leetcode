#include<bits/stdc++.h>
using namespace std;
int missing(vector<int>&nums) {
	int xori = 0;
	for (int i = 0; i < nums.size(); i++) {
		xori = xori ^ nums[i];
	}
	for (int i = 1; i <= nums.size() + 1; i++) {
		xori = xori ^ i;
	}
	return xori;
}
int main() {
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << missing(nums);
}
