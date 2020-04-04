#include<bits/stdc++.h>
using namespace std;
string simplfypath(string path) {
	string ret, tmp;
	
	vector<string> Stack;
	for (istringstream iss(path); getline(iss, tmp, '/');) {
		if (tmp == ".." and !Stack.empty())
			Stack.pop_back();
		else if (tmp == "." or tmp == ".." or tmp == "") continue;
		else Stack.push_back(tmp);
	}
	for (auto str : Stack) {ret += "/" + str;}
	return ret.empty() ? "/" : ret;
}
int main() {
	string s;
	cin >> s;
	cout << simplfypath(s);
}