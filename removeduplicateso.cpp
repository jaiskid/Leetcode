#include<bits/stdc++.h>
using namespace std;
int removedup_(vector<int> &nums) {
	int last = -1;

	for (const auto &num : nums) {
		if (last = -1 || nums[last] != num)
			nums[++last] = num;
	}
	return last + 1;
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
	cout << removedup_(nums);

}