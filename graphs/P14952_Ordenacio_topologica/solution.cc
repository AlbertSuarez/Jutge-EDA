#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef vector<vector<int> > Graph;

list<int> ordenacio_topologica(const Graph& g) {
	int n = g.size();
	vector <int> ge(n,0);
	for (int u = 0; u < n; ++u) {
		for (int i = 0; i < (int)g[u].size(); ++i) ++ge[g[u][i]];
	}
	priority_queue <int, vector<int>, greater<int> > S;
	for (int i = 0; i < n; ++i) {
		if (ge[i] == 0) S.push(i);
	}
	list <int> l;
	while (not S.empty()) {
		int x = S.top();
		S.pop();
		l.push_back(x);
		for (int i = 0; i < (int)g[x].size(); ++i) {
			int v = g[x][i];
			if (--ge[v] == 0) S.push(v);
		}
	}
	return l;
}

int main() {
	int n, m;
	while(cin >> n >> m) {
		Graph g (n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
		}
		list <int> l;
		l = ordenacio_topologica(g);
		list<int>::const_iterator it = l.begin();
		cout << *it;
		++it;
		while (it != l.end()) {
			cout << " " << *it;
			++it;
		}
		cout << endl;
	}
}