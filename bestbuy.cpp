#include<bits/stdc++.h>
using namespace std;
int maximiseProfit(int *prices, int n) {
	int dp[n + 1];
	dp[0] = 0;
	for (int i = 1; i < n + 1; i++) {
		dp[i] = max(prices[i] - prices[i - 1] + dp[i - 1], 0);
	}
	return dp[n];
}
int main() {
	int n;
	cin >> n;
	int prices[n];
	for (int i = 0; i < n; i++)
		cin >> prices[i];
	cout << maximiseProfit(prices, n);
}