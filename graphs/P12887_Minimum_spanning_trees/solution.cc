#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,pair<int, int> > WEdge;
typedef vector<vector<pair<int,int> > > WGraph;

void prim(const WGraph& graph) {
	vector<bool> used(graph.size(), false);
	vector<int> parent(graph.size(), -1);
	priority_queue<WEdge, vector<WEdge>, greater<WEdge> > q;

	int suma = 0;
	q.push(make_pair(0, make_pair(0, 0)));
	while (not q.empty()) {
		WEdge t = q.top();
		q.pop();

		int p = t.first;
		int u = t.second.first;
		int v = t.second.second;
		if (not used[v]) {
			used[v] = true;
			parent[v] = u;
			suma += p;
			for (int i = 0; i < graph[v].size(); i++) {
				int pes = graph[v][i].first;
				int vertex = graph[v][i].second;
				q.push(make_pair(pes, make_pair(v, vertex)));
			}
		}
	}

	cout << suma << endl;
}

int main() {
	int vertexs, edges;
	while (cin >> vertexs >> edges) {
		WGraph graph(vertexs);
		int u, v, w;
		for (int i = 0; i < edges; i++) {
			cin >> u >> v >> w;
			--u; --v;
			graph[u].push_back(make_pair(w, v));
			graph[v].push_back(make_pair(w, u));
		}
		prim(graph);
	}
}