#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int countbits(int n){
	int count=0;
	while(n){
	count++;
	n=n&(n-1);
	}
	return count;
}
// custom comparator of std::sort 
int cmp(int a,int b) 
{ 
    int count1 = countbits(a); 
    int count2 = countbits(b); 
  
    // this takes care of the stability of 
    // sorting algorithm too 
    if (count1 >= count2) 
        return false; 
    return true; 
} 
void stability(int *arr,int n){
	sort(arr,arr+n,cmp);
}

int main(){
	int n;
	cin>>n;
	//cout<<countbits(n);
	int arr[10005];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	stability(arr,n);
	vector<int> a;
	for(int i=0;i<a.size();i++){
		a.push_back(arr[i]);
	}
	for(auto it=a.begin();it!=a.end();it++){
			cout<<*it<<" ";
	}
}