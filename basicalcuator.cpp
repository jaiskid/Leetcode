#include <bits/stdc++.h>
using namespace std;
int calculator(string s) {
	int sign = 1;
	int  sum = 0;
	stack<int> Stack;
	for (int i = 0; i < s.length(); i++) {
		int num = 0;
		if (s[i] >= '0' and s[i] <= '9') {
			while (i<s.length() and s[i] >= '0' and s[i] <= '9') {
				num = num * 10 + (s[i] - '0');
				i++;
			}
			sum += num * sign;
			i--;
		}
		else if (s[i] == '+') {
			sign = 1;
		}
		else if (s[i] == '-') {
			sign = -1;
		}
		else if (s[i] == '(') {
			Stack.push(sum);
			Stack.push(sign);
			sum = 0;
			sign = 1;
		} else if (s[i] == ')') {
			sum = Stack.top() * sum;
			Stack.pop();
			sum += Stack.top();
			Stack.pop();
		}
	}
	return sum;
}
int main() {
	string s;
	cin >> s;
	cout << calculator(s);
}