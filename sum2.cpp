#include<bits/stdc++.h>
using namespace std;
vector<int> two(vector<int>&numbers, int target) {
	int left = 0, right = numbers.size() - 1;

	while (left != right) {
		const auto sum = numbers[left] + numbers[right];
		if (sum > target) {
			--right;
		}
		else if (sum < target) {
			++left;
		}
		else
			return {left + 1, right + 1};
		}
	return {0, 0};
}
int main() {
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int target;
	cin >> target;
	vector<int> indices;
	indices = two(nums, target);
}