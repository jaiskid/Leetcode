#include<bits/stdc++.h>
using namespace std;
int maxsum(vector<int>&nums){
	vector<int>dp({0,INT_MIN,INT_MIN});
	for( int num : nums){
	vector<int> temp({0,INT_MIN,INT_MIN});
	for(int i=0;i<3;i++){
	int rem=(i+num)%3;
	temp[rem]=max(dp[i]+num,dp[rem]);
	}
	dp=temp;
	}
	return dp[0];
}
int main(){
	int n;
	cin>>n;
	vector<int> nums;
	while(n--){
	int data;
	cin>>data;
	nums.push_back(data);
	}
	cout<<maxsum(nums);
}