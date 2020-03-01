//o(n)-time space o(1)
#include<iostream>
#include<vector>
using namespace std;
vector<int>runencode(int *arr,int n){
	vector<int> result;
	for(int i=0;i<n;i+=2){
	for(int j=0;j<arr[i];j++){
		result.emplace_back(arr[i+1]);
	 }
	}
	return result;
}
int main(){
	int n;
	cin>>n;
	int arr[10005];
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	vector<int> a;
	a=runencode(arr,n);
	for(int i=0;i<n;i++){
	cout<<a[i]<<" ";
	}
}