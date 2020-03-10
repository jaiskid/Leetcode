#include<iostream>
#include<vector>
using namespace std;
void moveszeroes(vector<int>&nums){
	int pos=0;
	for(auto & num: nums){
	swap(nums[pos++],num);
	}
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
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
}