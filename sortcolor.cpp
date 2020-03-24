#include <bits/stdc++.h>
using namespace std;
void sortcolors(vector<int>&nums) {
	static const int target	= 1;
	for (int i = 0, left = 0, right = nums.size() - 1; i <= right;) {
		if (nums[i] > target) // this is handling the 2
			swap(nums[i], nums[right--]);
		else {
			if (nums[i] < target)
				swap(nums[left++], nums[i]);
			++i;
		}
	}

}
int main() {
	int n; cin >> n;
	vector<int> nums;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sortcolors(nums);
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
}