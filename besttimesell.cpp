#include<bits/stdc++.h>
using namespace std;
int maxprofit(vector<int>&prices){
	if(prices.empty())
	return 0;
	int hold=INT_MIN;
	int release=INT_MIN;
	for(const auto & p:prices){
	hold=max(hold,-p);
	release=max(release,hold+p);
	}
	return release;
}
int main(){
int n;
cin>>n;
vector<int> prices;

while(n--){
int data;
cin>>data;
prices.push_back(data);
}
cout<<maxprofit(prices);
}
