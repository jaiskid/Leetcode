#include<bits/stdc++.h>
using namespace std;
vector<int>intersection(vector<int>&nums1, vector<int>&nums2) {
	if (nums1.size() > nums2.size())
		return intersection(nums2, nums1);
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	vector<int> result;
	auto it = nums2.cbegin();
	for (const auto & i : nums1) {
		it = lower_bound(it, nums2.cend(), i);
		if (it != nums2.end() and * it == i)
			result.emplace_back(*it);
		it = upper_bound(it, nums2.cend(), i);
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<int> nums1;
	vector<int>	nums2;
	while (n--) {
		int data;
		cin >> data;
		nums1.push_back(data);
	}
	while (m--) {
		int data;
		cin >> data;
		nums2.push_back(data);
	}
	vector<int> result;
	result = intersection(nums1, nums2);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}