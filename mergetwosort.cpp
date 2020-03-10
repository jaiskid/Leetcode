#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&nums1,int m,vector<int>&nums2,int n){
	int i=m+n;
	while(m>0 and n>0){
	if(nums1[m-1]>nums2[n-1]){
	nums1[i-1]=nums1[m-1]; // bigger element at last index
	--m;
	}
	else{
	nums1[i-1]=nums2[n-1]; 
	--n;
	}
	--i;
	}
	while(n>0){
	nums1[i-1]=nums2[n-1];
	n--;
	i--;

	}
}
int main(){
	int m,n;
	cin>>m>>n;
	vector<int> nums1,nums2;
	while(m--){
	int data;
	cin>>data;
	nums1.push_back(data);
	}
	while(n--){
	int data;
	cin>>data;
	nums2.push_back(data);
	}
	merge(nums1,m,nums2,n);
	for(int i=0;i<nums1.size();i++){
		cout<<nums1[i]<<" ";
	}
}