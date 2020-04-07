#include<bits/stdc++.h>
using namespace std;
template <typename T>
class graph {
	map<T, list<T>> adjList;
public:
	graph() {

	}
	void addEgde(T u, T v, bool bidir = true) {
		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}
	void print() {
		for (auto i : adjList) {
			cout << i.first << "->";
			for (auto entry : i.second) {
				cout << entry << " ";
			}
			cout << endl;
		}
	}
	void bfs(T src) {
		queue<T>q;
		q.push(src);
		map<T, bool> visited;
		visited[src] = true;
		while (!q.empty()) {
			T node = q.front();
			cout << node << " ";
			q.pop();
			for (auto neighbour : adjList[node]) {
				if (!visited[neighbour]) {
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}
	void dfshelper(T node, map<T, bool> &visited) {
		//when come to a node mark it visited
		visited[node] = true;
		cout << node << " ";
		for (auto neighbour : adjList[node]) {
			if (!visited[neighbour]) {
				dfshelper(neighbour, visited);
			}
		}
	}
	void dfs(T src) {
		map<T, bool> visited;
		int component = 1;
		dfshelper(src, visited);
		//node and linked list pair
		for (auto i : adjList) {
			T num = i.first;
			if (!visited[num]) {
				dfshelper(num, visited);
				component++;
			}
		}
		cout << component;
	}
};
int main() {
	graph<int>g;
	g.addEgde(0, 1);
	g.addEgde(0, 4);
	g.addEgde(1, 2);
	g.addEgde(2, 3);
	g.addEgde(4, 3);
	g.addEgde(3, 5);
	g.addEgde(6, 9);
	g.dfs(0);
}