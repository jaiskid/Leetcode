#include<bits/stdc++.h>
using namespace std;
string decode(string s) {
	stack<string> chars;
	stack<int> nums;
	string res;
	int num = 0;
	for (char c : s) {
		/* four cases arise for this problem
		number case
		letter case
		open bracket case
		close bracket case
		*/
		if (isdigit(c)) {
			num = num * 10 + (c - '0');
		}
		else if (isalpha(c)) {
			res.push_back(c);
		}
		else if (c == '[') {
			chars.push(res);
			nums.push(num);
			//Reset back to default
			res = "";
			num = 0;
		}
		else if (c == ']') {
			string temp = res;
			for (int i = 0; i < nums.top() - 1; ++i) {
				res += temp;
			}
			res = chars.top() + res;
			chars.top();
			nums.pop();
		}
	}
	return res;
}
int main() {
	string s;
	cin >> s;
	cout << decode(s);
}