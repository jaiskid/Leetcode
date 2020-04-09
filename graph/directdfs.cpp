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
	bool iscyclichelper(T node , map<T, bool> &visited, map<T, bool> & instack) {
		//processing the current node visited ,In stack
		visited[node] = true;
		instack[node] = true;
		for (T neighbour : adjList[node]) {
			if (!visited[neighbour] and iscyclichelper(neighbour, visited, instack) || instack[neighbour]) {
				return true;
			}
		}
		instack[node] = false;
		return false;
	}
	bool iscyclic() {
		map<T, bool> visited;
		map<T, bool> instack;
		for (auto i : adjList) {
			T node = i.first;
			if (!visited[node]) {
				bool cyclepresent = iscyclichelper(node, visited, instack);
				if (cyclepresent) {
					return true;
				}
			}

		}
		return false;
	}
};
int main() {
	graph<int>g;
	g.addEgde(0, 2, false);
	g.addEgde(0, 1, false);
	g.addEgde(2, 3, false);
	g.addEgde(2, 4, false);
	//g.addEgde(3, 0);
	g.addEgde(4, 5, false);
	g.addEgde(1, 5, false);
	if (g.iscyclic()) {
		cout << "Cyclic" << endl;
	}
	else {
		cout << "Not cyclic" << endl;
	}
}