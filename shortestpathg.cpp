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
		//this visited for marking purpose
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

	void shortest(T src) {
		queue<T>q;
		q.push(src);
		//for particular node mark distance
		map<T, int> dist;
		// for particular node to child parent relationship
		map<T, T> parent;
		//Initially all the mark as INT_MAX
		for (auto i : adjList) {
			dist[i.first] = INT_MAX;
		}
		dist[src] = 0;
		while (!q.empty()) {
			T node = q.front();
			q.pop();
			//cout << node << " ";
			for (auto neighbour : adjList[node]) {
				if (dist[neighbour] == INT_MAX) {
					q.push(neighbour);
					dist[neighbour] = dist[node] + 1;
					parent[neighbour] = node;
				}
			}
		}
		for (auto i : adjList) {
			T node = i.first;
			cout << "dist of " << node << " from " << src << " is " << dist[node] << endl;
		}
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
	//g.bfs(0);
	cout << endl;
	g.shortest(0);
}