#include<bits/stdc++.h>
using namespace std;
int score_(string s) {
	stack<int> Stack;
	int score = 0;
	for (char c : s) {
		if (c == '(') {
			Stack.push(score);
			score = 0;
		}

		else {
			auto last = Stack.top();
			score = last + max(2 * score, 1);
		}
	}
	return score;
}
int main() {
	string s;
	cin >> s;
	cout << score_(s);
}