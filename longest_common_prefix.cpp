#include<iostream>
#include<vector>
using namespace std;
string longestprefix(vector<string> &strs){
	if(strs.empty()){
	return " ";
	}
	for(int i=0;i<strs[0].length();i++){
	for(const auto str :strs){
	if(i>=str.length()||str[i]!=strs[0][i]){
		return strs[0].substr(0,i);
		}
 	}
 }
 return strs[0];
}
int main(){
	int n;
	cin>>n;
	vector<string> strs;
	while(n--){
	string s;
	cin>>s;
	strs.push_back(s);
	}
	cout<<longestprefix(strs);
}
