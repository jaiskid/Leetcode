#include<bits/stdc++.h>
#define pb push_back
using namespace std;
class Graph {
	int V;
	list<int> *l;
public:
	Graph(int v) {
		V = v;
		//Array of linked lists
		l = new list<int>[v];
	}
	void addEdge(int u, int v, bool bidir = true) {
		l[u].pb(v);
		if (bidir) {
			l[v].pb(u);
		}
	}
	void printAd() {
		for (int i = 0; i < V; i++) {
			cout << i << "->";
			//l[i] is a linked list
			for (auto vertex : l[i]) {
				cout << vertex << " ";
			}
			cout << endl;
		}
	}
};
int main() {
	Graph g(5);
	int x, y;
	for (int i = 0; i < 7; i++) {

		cin >> x >> y;
		g.addEdge(x, y);
	}
	g.printAd();
	return 0;
}