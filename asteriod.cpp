#include<bits/stdc++.h>
using namespace std;
vector<int> asteroid_(vector<int>&asteroid) {
	stack<int>Stack;
	for (int i = 0; i < asteroid.size(); i++) {
		if (Stack.empty() or asteroid[i] > 0) {
			Stack.push(asteroid[i]);
		} else {
			while (true) {
				int top = Stack.top();
				if (top < 0) {
					Stack.push(asteroid[i]);
					break;
				} else if (top == -asteroid[i]) {
					Stack.pop();
					break;
				}
				else if (top > -asteroid[i]) {
					break;
				}
				else {
					Stack.pop();
					if (Stack.empty()) {
						Stack.push(asteroid[i]);
						break;
					}
				}
			}
		}
	}

	vector<int> output;
	output.resize(Stack.size());
	for (int i = Stack.size() - 1; i >= 0; i--) {
		output[i] = Stack.top(); Stack.pop();
	}
	return output;
}
int main() {
	int n;
	cin >> n;
	vector<int> asteroid;
	asteroid.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> asteroid[i];
	}
	vector<int> output(n);
	output = asteroid_(asteroid);
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << " ";
	}
}