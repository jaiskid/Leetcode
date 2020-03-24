#include<bits/stdc++.h>
using namespace std;
bool parity(vector<int>&bits) {
	auto parity = 0;
	for (int i = static_cast<int>(bits.size()) - 2; i >= 0 and bits[i] ; i--)
		parity ^= bits[i];
	return parity == 0;
}
int main() {
	int n;
	cin >> n;
	vector<int>bits;
	bits.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> bits(n);
	}
	cout << parity(bits) << endl;
}