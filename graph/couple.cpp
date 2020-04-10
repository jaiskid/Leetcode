#include<bits/stdc++.h>
using namespace std;
class UF {
public:
    UF(int n):
        parent(n) {}

    void set_parent(int x, int p) {
        parent[x] = p;
    }
    int find(int x) {
        if (x == parent[x])
            return parent[x];
        else
            return parent[x] = find(parent[x]);
    }
    bool union_find(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return false;
        parent[px] = py;
        return true;
    }
private:
    vector<int>parent;
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        if (row.empty()) return 0;
        UF uf(row.size());
        for (int i = 0; i < row.size(); i += 2) {
            uf.set_parent(row[i], row[i]);
            uf.set_parent(row[i + 1], row[i]);
        }
        int counter = 0;
        for (int i = 0; i < row.size(); i += 2) {
            if (uf.union_find(i, i + 1))
                counter++;
        }
        return counter;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> row;
    row.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> row[i];

    }
    Solution s;
    cout << s.minSwapsCouples(row);
}