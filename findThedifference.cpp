#include<bits/stdc++.h>
using namespace std;
char stringthedifference(string s,string t){
	return accumulate(s.cbegin(),s.cend(),0,bit_xor<int>())^accumulate(t.cbegin(),t.cend(),0,bit_xor<int>());
}
int main(){
	string s,t;
	cin>>s>>t;
	cout<<stringthedifference(s,t);
}