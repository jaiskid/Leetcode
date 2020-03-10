#include<iostream>
using namespace std;
int majority(vector<int> &nums){
	int ans=nums[0],cnt=1;
	for(const auto &i : nums){
	if(i==ans){
	++cnt;
	}
	else{
	--cnt;
	if(cnt==0)
	{
	ans=i;
	cnt=1;
	}
	}
	}
	return ans;
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

}