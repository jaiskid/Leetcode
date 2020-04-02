#include<bits/stdc++.h>
using namespace std;
class solution {
public:
	bool isHappy(int n) {
		unordered_set<int>visited;
		while (n != 1 and !visited.count(n)) {
			visited.emplace(n);
			n = nextNumber(n);
		}
		return n == 1;
	}
public:
	int nextNumber(int n) {
		int sum = 0;
		while (n) {
			sum += pow(n % 10, 2);
			n /= 10;
		}
		return sum;
	}
};
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	solution s;
	cout << s.isHappy(n);
	return 0;
}