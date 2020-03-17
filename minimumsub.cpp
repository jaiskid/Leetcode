#include<bits/stdc++.h>
using namespace std;
int minSubarray(int s,vector<int>&nums){
	int start=-1,min_value=INT_MAX,sum=0;
	for(int i=0;i<nums.size();i++){
		sum+=nums[i];
		while(sum>=s){
			cout<<start<<" ";
		//cout<<i-start<<" ";
		min_value=min(min_value,i-start);

		sum-=nums[++start];
		}

	}
	return (min_value==INT_MAX)?0:min_value;
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
int s;
cin>>s;
cout<<minSubarray(s,nums);
}