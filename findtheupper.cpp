#include<bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
	auto it1 = lower_bound(nums.begin(), nums.end(), target);
	auto it2 = upper_bound(nums.begin(), nums.end(), target);
	if (it1 != nums.end() and * it1 == target)
		return {it1 - nums.begin(), it2 - nums.begin() - 1};
	return { -1, -1};
}
int main() {
	int n;
	cin >> n;
	vector<int> nums;
	while (n--) {
		int data;
		cin >> data;
		nums.push_back(data);
	}
	int target;
	cin >> target;
	nums = searchRange(nums, target);
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
}
