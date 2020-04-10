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
	int snake_ladder(T src , T dest) {
		queue<T> q;
		map<T, int> dist;
		map<T, T> parent;
		q.push(src);
		for (auto i : adjList) {
			dist[i.first] = INT_MAX;
		}
		dist[src] = 0;
		while (!q.empty()) {
			T node = q.front();
			q.pop();
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
			//cout << "dist of " << node << " is " << dist[node] << endl;
		}
		//You can destina
		T temp = dest;
		while (temp != src) {
			cout << temp << "<---";
			temp = parent[temp];
		}
		cout << src << endl;
		return dist[dest];
	}
	
};
int main() {
	graph<int> g;

	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;
	for (int u = 0; u <= 36; u++) {
		for (int dice = 1; dice <= 6; dice++) {
			int v = u + dice + board[u + dice];
			g.addEgde(u, v, false);
		}
	}
	cout << "The shortest path dist is " << g.snake_ladder(0, 36) << endl;
}