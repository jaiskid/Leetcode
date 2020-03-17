#include<bits/stdc++.h>
#include <utility>
void countAndmerge(vector<pair<int,int>>&num_idx,int start,int end,vector<int> &counts){
	if(end-start<=0)
	return;
	int mid=start+(end-start)/2;
	countAndmerge(num_idx,start,mid,counts);
	countAndmerge(num_idx,mid+1,end,count);
	int r=mid+1;
	vector<pair<int,int>> tmp;
	for(int i=start;i<=mid;++i){
	//Merge the two sorted array into the temp;
	while(r<=end &&(num_idx)[r].first<(*num_idx)[i].first)
		{
			tmp.emplace_back((*num_idx)[r++]);
		}
		tmp.emplace_back((*num_idx)[i]);
		(*counts)[(*num_idx)[i].second]+=r-(mid+1);
	}
	 copy(tmp.begin(), tmp.end(), num_idxs->begin() + start);
}
vector<int>countSmaller(vector<int>&nums){
	vector<int> counts(nums.size());
	
	for(int i=0;i<nums.size();i++){
	num_idx.emplace_back(nums[i],i);
	}
	countAndmerge(num_idx,0,num_idx.size()-1,counts);
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
	vector<int> counts;
	count=countSmaller(nums);
	for(int i=0;i<counts.size();i++){
		cout<<counts[i]<<" ";
	}
}