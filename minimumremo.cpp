#include<bits/stdc++.h>
using namespace std;
string minRemove(string s) {
	stack<int>Stack;
	for (auto i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			Stack.push(i);
		if (s[i] == ')') 
			if (!Stack.empty())
				Stack.pop();
		else
			s[i] = '*';
	}
	//this case for more open bracket
	while (!Stack.empty()) {
		s[Stack.top()] = '*';
		Stack.pop();
	}
	s.erase(remove(s.begin(), s.end(), '*'), s.end());
	return s;
}
int main() {
	string s;
	cin >> s;
	string res = minRemove(s);
	cout << res;
}