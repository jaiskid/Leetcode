// Time o(n)
// space o(1)
#include<iostream>
#include<vector>
using namespace std;
int height_(vector<int>& height){
	int i=0;
	int j=height.size()-1;
	int max_area=0;
	while(i<j){
		max_area=max(max_area,min(height[i],height[j])*(j-i));
		if(height[i]>height[j])
		j--;
		else if(height[i]<height[j])
		i++;
		else
		i++,j--;

	}
	return max_area;
}

int main(){
	
	int n;
	cin>>n;
	vector<int> height(n);
	while(n--){
		int data;
		cin>>data;
		height.push_back(data);
	}
	cout<<height_(height);
}