#include<bits/stdc++.h>
using namespace std;
void bucketsort(vector<int>&nums) {
	int i = 0;
	while (i < nums.size()) {
		if (nums[i] > 0 and nums[i] <= nums.size() and nums[i] != nums[nums[i] - 1]) {
			swap(nums[i], nums[nums[i] - 1]);
		}
		else {
			i++;
		}
	}
}
int firstmissingpositive(vector<int>&nums) {

	bucketsort(nums);
	int i = 0;
	for (; i < nums.size() and nums[i] == i + 1; i++);
	return i + 1;
}
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << firstmissingpositive(nums);
}