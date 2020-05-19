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
unordered_map<int, vector<int> >h;
vector<int> findAll(int i, vector<int>&v) {
	if (h.count(i)) {
		return h[i];
	}
	vector<int> ans;
	for (int j = 0; j < i; j++) {
		if (v[i] % v[j] == 0) {
			auto x = findAll(j, v);
			if (x.size() > ans.size()) {
				ans = x;
			}
		}
	}
	ans.pb(v[i]);
	return h[i] = ans;
}
vector<int> largestDivisibleSubset(vector<int>&nums) {
	int n = nums.size();
	vector<int> ans;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; i++) {
		auto x = findAll(i, nums);
		if (ans.size() < x.size())
			ans = x;
	}
	return ans;
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> nums;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<int>Div;
	Div = largestDivisibleSubset(nums);
	for (int i = 0; i < Div.size(); i++) {
		cout << Div[i] << " ";
	}
}