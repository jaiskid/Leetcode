#include<bits/stdc++.h>
using namespace std;
vector<int> dailytemperature(vector<int>&temp) {
	vector<int> result;
	result.resize(temp.size());
	stack<int>Stack;
	for (int i = 0; i < temp.size(); i++) {
		while (!Stack.empty() and temp[Stack.top()] < temp[i]) {
			const auto idx = Stack.top();
			Stack.pop();
			result[idx] = i - idx;
		}
		Stack.emplace(i);
	}
	return result;
}
int main() {
	int n;
	cin >> n;
	vector<int>temp;
	temp.resize(n);
	for (int i = 0; i < n; i++)
		cin >> temp[i];
	vector<int> result = dailytemperature(temp);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
}