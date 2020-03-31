#include<bits/stdc++.h>
using namespace std;
bool isvalid(string s) {
	int i = 0, j = s.length() - 1;
	while (i < j) {
		if (!isalnum(s[i]))
			++i;
		else if (!isalnum(s[j]))
			--j;
		else if (tolower(s[i]) != tolower(s[j]))
			return false;
		else
			++i, --j;
	}
	return true;
}
int main() {
	string s;
	getline(cin, s);
	cout<<s<<" ";
	cout << isvalid(s);
}