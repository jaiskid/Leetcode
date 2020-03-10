//time o(n)
//space o(1)
#include<iostream>
#include<vector>
using namespace std;
int max_area(vector<int> &height){
	int i=0;
	int j=height.size()-1;
	int trap=0;
	int left_height=height[0];
	int right_height=height[height.size()-1];
	while(i<j){
	if(left_height<right_height){
	i++;
			//fill the gap
		trap+=max(0,left_height-height[i]);
		left_height=max(left_height,height[i]);
		}
	else{
		j--;
		trap+=max(0,right_height-height[j]);
		right_height=max(right_height,height[j]);
	}
	}
	return trap;
}
int main(){
	vector<int> height;
	int n;
	cin>>n;
	while(n--){
		int data;
		cin>>data;
		height.push_back(data);
	}
	cout<<max_area(height);
}