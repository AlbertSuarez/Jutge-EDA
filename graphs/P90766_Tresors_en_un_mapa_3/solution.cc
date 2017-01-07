#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector< vector<char> > graph;
typedef pair<int,int> P;

const int F[4] = {0, 0,1,-1};
const int C[4] = {1,-1,0, 0};
const int UNDEF = -1;

bool ok(int n, int m, int f, int c) {
  return (f >= 0 and f < n and c >= 0 and c < m);
}

int buscar_tresor(int n, int m, int f0, int c0, graph& g, vector< vector<bool> >& nv) {
  int resul = 0;
  if (g[f0][c0] =='t') ++resul;
  nv[f0][c0] = false;
  if (g[f0][c0]!='X') {
      for (int k = 0; k<4;++k) {
	int ff = f0 + F[k];
	int cc = c0 + C[k];
	if (ok(n,m,ff,cc) and g[ff][cc]!='X' and nv[ff][cc]) resul = resul + buscar_tresor(n, m, ff, cc, g, nv);
      }
   }
   return resul;
}

int main() {
  int n, m;
  cin >> n >> m;
  graph g (n, vector<char>(m));
  for (int i =0; i < n; ++i) {
     for (int j =0; j < m; ++j) {
        cin >> g[i][j];
     }
  }

  int f, c;
  cin >> f >> c;
  vector< vector<bool> > novist(n, vector<bool>(m, true));
  int dist = buscar_tresor(n, m, f-1, c-1, g, novist);
  cout << dist << endl;
}
