#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
	map<T, list<T>> adjList;
public:
	Graph() {

	}
	void addEdge(T u, T v, bool bidir = true) {
		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}
	void topological() {
		queue<T> q;
		map<T, bool> visited;
		map<T, int> indegree;
		for (auto i : adjList) {
			//i is the pair of node and its list
			T node = i.first;
			visited[node] = false;
			indegree[node] = 0;

		}
		//Init the indegree of all nodes
		for (auto i : adjList) {
			T u = i.first;
			for (T v : adjList[u]) {
				indegree[v]++;
			}
		}
		for (auto i : adjList) {
			T node = i.first;
			if (indegree[node] == 0)
				q.push(node);
		}
		while (!q.empty()) {
			T node = q.front();
			q.pop();
			cout << node << "-->";
			for (T neighbour : adjList[node]) {
				indegree[neighbour]--;
				if (indegree[neighbour] == 0) {
					q.push(neighbour);
				}
			}
		}
	}
};
int main() {
	Graph<int>g;
	g.addEdge(0, 1, false);
	g.addEdge(0, 2, false);
	g.addEdge(0, 4, false);
	g.addEdge(2, 4, false);
	g.addEdge(1, 4, false);
	g.addEdge(4, 5, false);
	g.topological();
}