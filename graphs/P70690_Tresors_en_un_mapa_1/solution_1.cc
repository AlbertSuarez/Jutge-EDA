#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<char> > Map;

bool buscar (Map& map, int x, int y) {
	int n = map.size();
	int m = map[0].size();
	if (x < n and y < m and x >= 0 and y >= 0) {
		if (map[x][y] == 'v') return false;
		if (map[x][y] == 't') return true;
		if (map[x][y] == 'X') return false;
		else map[x][y] = 'v';
		if (buscar(map,x-1,y)) return true;
		else if (buscar(map,x+1,y)) return true;		
		else if (buscar(map,x,y+1)) return true;		
		else if (buscar(map,x,y-1)) return true;
	}
	return false;
}


int main() {
	int n, m;				// n filas, m columnes
	cin >> n >> m;
	Map map(n,vector<char>(m));		// matriu de mapa
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	cout << (buscar(map, --x, --y)? "yes":"no") << endl;
}