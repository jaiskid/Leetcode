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
	bool iscycle(T src) {
		queue<T> q;
		map<T, bool> visited;
		map<T, int> parent;
		q.push(src);
		visited[src] = true;
		parent[src] = src;
		while (!q.empty()) {
			T node = q.front();
			q.pop();
			for (T neighbour : adjList[node]) {
				if (visited[neighbour] == true and parent[node] != neighbour) {
					return true;
				}
				else if (!visited[neighbour]) {
					visited[neighbour] = true;
					parent[neighbour] = node;
					q.push(neighbour);
				}
			}
		}
		return false;
	}
};
int main() {
	graph<int>g;
	g.addEgde(1, 2);
	g.addEgde(1, 3);
	g.addEgde(3, 4);
	g.addEgde(2, 4);
	if (g.iscycle(1)) {
		cout << "Cyclic" << endl;
	}
	else {
		cout << "not cyclic" << endl;
	}
}