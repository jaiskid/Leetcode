#include<bits/stdc++.h>
using namespace std;
int calculate(string s) {
	int depth = 0, result = 0;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '(')
			++depth;
		else {
			--depth;
			if (s[i - 1] == '(')
				result += 1 << depth;
		}
	}
	return result;
}
int main() {
	string s;
	cin >> s;
	cout << calculate(s);
}