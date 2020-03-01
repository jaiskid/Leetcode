//time o(n)
//space o(n)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int longestconsecutivesubsequence(vector<int> &nums){
	if(nums.empty())
	return 0;
	unordered_map<int,int > hash;
	int ans{1};
	for(auto i : nums){
	if(!hash[i]){
	hash[i]=1;
		int leftmost{hash[i-1]},rightmost{hash[i+1]};
		
		hash[i-leftmost]=hash[i+rightmost]=1+leftmost+rightmost;
		ans=max(ans,1+leftmost+rightmost);
	}
	}
	return ans;
}
int main(){
vector<int> nums;
int n;
cin>>n;
while(n--){
	int data;
	cin>>data;
	nums.push_back(data);
}
cout<<longestconsecutivesubsequence(nums);
}