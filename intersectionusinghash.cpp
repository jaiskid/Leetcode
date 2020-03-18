#include<bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int>&nums1,vector<int>&nums2){
	if(nums1.size()>nums2.size())
	{
		return intersection(nums2,nums1);
	}
	unordered_set<int> lookup{nums1.cbegin(),nums1.cend()};
	vector<int> result;
	for(const auto& i : nums2){
	if(lookup.count(i)){
		result.emplace_back(i);
		lookup.erase(i);
		}
	 }
	 return result;
	}
int main(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int> nums1;
	vector<int>	nums2;
	while(n--){
	int data;
	cin>>data;
	nums1.push_back(data);
	}	
	while(m--){
	int data;
	cin>>data;
	nums2.push_back(data);
	}
	vector<int> result;
	result=intersection(nums1,nums2);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
}