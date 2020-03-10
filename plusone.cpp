#include<iostream>
#include<vector>
using namespace std;
vector<int> plusone(vector<int>&digits){
	for(int i=digits.size()-1;i>=0;i--){
	if(digits[i]==9)
	digits[i]=0;
	else{
	++digits[i];
	return digits;
	}
	}
	digits[0]=1;//for the input like single 9
	digits.emplace_back(0);
	return digits;
}
int main(){
	int n;
	cin>>n;
	vector<int> digits;
	while(n--){
	int data;
	cin>>data;
	digits.push_back(data);
	}
	plusone(digits);
	for(int i=0;i<digits.size();i++){
	cout<<digits[i]<<" ";
	}
}