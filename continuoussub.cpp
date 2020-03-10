//time o(n)
//space o(1)
#include<iostream>
#include<limits>
#include<vector>
using namespace std;
int coutinuous(vector<int>& nums){
	int result=numeric_limits<int>::min();
	int curr=numeric_limits<int> ::min();
	for(const auto & x : nums){
	curr=(curr==numeric_limits<int> ::min())?x:max(curr+x,x);
	result=max(result,curr);
	}
	return result;
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
	cout<<coutinuous(nums);
}