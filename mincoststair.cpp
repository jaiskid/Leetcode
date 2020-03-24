#include<iostream>
using namespace std;
int minCostClimbingStairs(vector<int>& cost) {
     vector<int> dp(3);
        for(int i=cost.size()-1;i>=0;--i){
            dp[i%3]=cost[i]+min(dp[(i+1)%3],dp[(i+2)%3]);
        }
        return min(dp[0],dp[1]);
}
int main(){
	int n;
	cin >> n;
	vector<int>cost;
	cost.resize(n);
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	cout<<minCostClimbingStairs(cost);
}