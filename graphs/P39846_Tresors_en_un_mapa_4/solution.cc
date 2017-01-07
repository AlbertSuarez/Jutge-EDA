// Recorregut en amplada

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char> > Matriu;
typedef pair<int, int> iipair;
typedef vector <vector <int> > mint;

void prova(int i, int j, Matriu& mapa, mint& distancia, queue<iipair>& q, int d) {
    if (i >= 0 and i < mapa.size() and j >= 0 and j < mapa[0].size()) {
        if (mapa[i][j] == '.' or mapa[i][j] == 't') {
            q.push(iipair(i, j));
            distancia[i][j] = d+1;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Matriu mapa (n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> mapa[i][j];
    }
    int f, c;
    cin >> f >> c;
    --f;
    --c;
    
    queue<iipair> q;
    q.push (iipair(f, c));
    mint distancia (n, vector<int> (m, -1));
    int dist = 0;
    distancia[f][c] = 0;
    while (not q.empty()) {
        iipair p = q.front();
        q.pop();
        if (mapa[p.first][p.second] == 't') {
            if (dist < distancia[p.first][p.second]) dist = distancia[p.first][p.second];
        }
        if (mapa[p.first][p.second] == '.' or mapa[p.first][p.second] == 't') {
            mapa[p.first][p.second] = 'v';
            prova(p.first-1, p.second, mapa, distancia, q, distancia[p.first][p.second]);
            prova(p.first+1, p.second, mapa, distancia, q, distancia[p.first][p.second]);
            prova(p.first, p.second+1, mapa, distancia, q, distancia[p.first][p.second]);
            prova(p.first, p.second-1, mapa, distancia, q, distancia[p.first][p.second]);
        }
    }
    if (dist != 0) cout << "distancia maxima: " << dist << endl;
   else cout << "no es pot arribar a cap tresor" << endl;
}
