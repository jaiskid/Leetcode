#include<bits/stdc++.h>
using namespace std;
int  minimumTotal (vector <vector < int >> & triangle) {
	vector < int > steps;
	for ( auto & v : triangle) {
		if (! steps. empty ()) {
		cout << "v.front() " << v.front() << endl;
		cout << "v.back() " << v.back() << endl;
			v. front () += steps. front ();
			v. back () += steps. back ();
			
		}
		for ( size_t i = 1 ; i < steps. size (); ++ i)
			v [i] += min (steps. at (i - 1 ), steps. at (i));
		steps = v;
	}
	return * min_element (steps. cbegin (), steps. cend ());
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>triangle = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> triangle[i][j];
		}
	}
	cout << minimumTotal(triangle);
}