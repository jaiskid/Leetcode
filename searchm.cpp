#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>&matrix,int target){
	const int m=matrix.size();
	const int n=matrix[0].size();
	if(m==0){
	return false;
	}
	if(n==0){
	return false;
	}
	int i=0,j=n-1;
	while(i<m&&j>=0){
	if(matrix[i][j]==target)
	return true;
	else if(matrix[i][j]>target)
	--j;
	else
	i++;
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	vector<vector<int>>matrix(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int data;
			cin>>data;
			matrix[i].push_back(data);
		}
	}
	int target;
	cin>>target;
	cout<<searchMatrix(matrix,target);
}