#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<bool> vbool;
typedef vector<vbool> mbool;
typedef vector<char> vchar;
typedef vector<vchar> mchar;
typedef pair<int, int> coord;
typedef queue<coord> qcoord;

void tractar(const mchar& mapa, int x, int y, mbool& visitat, qcoord& q) {
	int n = mapa.size();
	int m = mapa[0].size();
	if (x >= 0 and x < n and y >= 0 and y < m) {
		if (not visitat[x][y]) {
			visitat[x][y] = true;
			if (mapa[x][y] != 'X') q.push(coord(x, y));
		}
	}
}

bool bfs(const mchar& mapa, int f, int c) {
	int n = mapa.size();
	int m = mapa[0].size();
	mbool visitat(n, vbool(m, false));
	qcoord q;

	visitat[f][c] = true;
	q.push(coord(f, c));
	while(not q.empty()) {
		coord v = q.front();
		q.pop();
		if (mapa[v.first][v.second] == 't') return true;
		tractar(mapa, v.first - 1, v.second, visitat, q);		// UP
		tractar(mapa, v.first, v.second - 1, visitat, q);		// LEFT
		tractar(mapa, v.first + 1, v.second, visitat, q);		// DOWN
		tractar(mapa, v.first, v.second + 1, visitat, q);		// RIGHT
	}

	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	mchar mapa(n, vchar(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mapa[i][j];
		}
	}
	int f, c;
	cin >> f >> c;
	--f; --c;

	if (bfs(mapa, f, c)) cout << "yes" << endl;
	else cout << "no" << endl;
}