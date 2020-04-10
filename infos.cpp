#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int n; T-- > 0 && cin >> n; ) {
    vector<int> a(n);
    map<int, int> b;
    for (int i = 0; i < n; ++i) cin >> a[i], b[a[i]] = 0;
    vector<int> d;
    {
      int i = 1;
      for (auto& p : b) p.second = i++, d.push_back(p.first);
    }
    vector<int> c(n + 1);
    for (int i = 0, x, y = 0; i < n && cin >> x; ++i) {
      for (int u = b[a[i]]; u <= n; u += u & -u) ++c[u];
      y = max(y, b[a[i]]);
      int lo = 1, hi = y;
      while (lo < hi) {
        int mid = (lo + hi) / 2;
        int s = 0;
        for (int u = mid; u > 0; u -= u & -u) s += c[u];
        if (s < x) lo = mid + 1; else hi = mid;
      }
      cout << d[lo - 1] << ' ';
    }
    cout << '\n';
  }

  return 0;
}