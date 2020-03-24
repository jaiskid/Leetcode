#include<bits/stdc++.h>
using namespace std;
vector<int> sortArrayByParity(vector<int>&A) {
	for (int i = 0, j = 0; j < A.size(); j++) {
		if (A[j] % 2 == 0)
			swap(A[j], A[i++]);
	}
	return A;
}
int main() {
	int n;
	cin >> n;
	vector<int>A;
	A.resize(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	A = sortArrayByParity(A);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}