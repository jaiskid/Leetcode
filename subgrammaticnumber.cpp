#include<bits/stdc++.h>
using namespace std;
const unordered_map<string,string> lookup{{"0","0"},{"1","1"},{"6","9"},{"8","8"},{"9","6"}};
vector<string> findsubgrammaticRec(const int n,int k){
	if(k==0){
	return {""};
	}
	else if(k==1){
	return {"0","1","8"};
	}
	vector<string> result;
	for(const auto &num: findsubgrammaticRec(n,k-2)){
	for(const auto & kvp:lookup){
	result.emplace_back(kvp.first+num+kvp.second);
	}
	}
	return result;
}
vector<string> findsubgrammatic(int n){
	return findsubgrammaticRec(n,n);
}
int main(){
int n;
cin>>n;
vector<string> res=findsubgrammatic(n);	
for(int i=0;i<res.size();i++)
{
	cout<<res[i]<<" ";
}
}