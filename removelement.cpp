#include<bits/stdc++.h>
using namespace std;
int removeElement(vector<int>&nums, int val) {
	int left = 0, right = nums.size();
	while (left < right) {
		if (nums[left] != val) {
			++left;
		}
		else {
			swap(nums[left], nums[--right]);
		}
	}
	return right;
}
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int val;
	cin >> val;
	cout << removeElement(nums, val);
	for (int i = 0; i < n; i++) {
		cout << nums[i]<<" ";
	}
}