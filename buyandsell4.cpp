#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007
int maxProfit(int K, vector<int>& prices) {
	if (K == 0 || prices.size() <= 1) return 0;
	int n = prices.size();
	if (K >= prices.size() / 2) {
		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (prices[i] > prices[i - 1])
				ans += prices[i] - prices[i - 1];
		}
		return ans;
	}

	int dp[1001][1001] = {0};
	for (int k = 1; k <= K; k++) {
		for (int i = 1; i < n; i++) {
			int ans = 0;
			for (int j = 0; j < i; j++) {
				if (prices[i] > prices[j])
					ans = max(prices[i] - prices[j] + dp[k - 1][j], ans);
			}
			dp[k][i] = max(ans, dp[k][i - 1]);
		}
	}
	cout << dp[K][n - 1];
	return dp[K][n - 1];
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int K;
	cin >> K;
	int n;
	cin >> n;
	vector<int> prices;
	prices.resize(n);
	F(prices, n);
	P(prices, n);
	cout << maxProfit(K, prices);
}