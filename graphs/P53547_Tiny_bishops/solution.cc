#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct Pos{
  int x;
  int y;
  Pos():x(), y(){}
  Pos(int a, int b):x(a), y(b){}
};

typedef vector<vector<int> > Matriu;
typedef vector<vector<bool> > Mbool;

const int X[4] = {-1, 1, 1, -1};
const int Y[4] = {1, 1, -1, -1};

bool valida(Matriu& m, Mbool& mb, Pos p){
    if(p.x >= 0 and p.x < m.size() and p.y >= 0 and p.y < m[0].size() and m[p.x][p.y] != -1 and not mb[p.x][p.y])
        return true;
    else return false;
}

int sumar_bishops(Matriu& m, Mbool& mb, int i, int j, bool& repartir){
   queue<Pos> q;
   int sum = 0, nElem = 0;
   q.push(Pos(i,j));
   mb[i][j] = true;

   while(not q.empty()){
      Pos act = q.front();
      sum += m[act.x][act.y];
      ++nElem;
      q.pop();
      for(int i = 0; i < 4; ++i){
         Pos next(act.x + X[i], act.y + Y[i]);
         if(valida(m, mb, next)){
            q.push(next);
            mb[next.x][next.y] = true;
         }
      }
   }
   repartir = ((sum%nElem) == 0);
   return sum/nElem;
}

bool posar_bishops(Matriu& m){
   int f, c;
   f = m.size();
   c = m[0].size();
   Mbool mb(f, vector<bool>(c, false));
   int sumAnt, suma;
   bool repartir, primer;
   repartir = primer = true;

   for (int i = 0; i < f; ++i) {
      for (int j = 0; j < c; ++j) {
         if(m[i][j] != -1 and not mb[i][j]) {
            suma = sumar_bishops(m, mb, i, j, repartir);
            if (primer) {
               primer = false;
               sumAnt = suma;
            }
            if (not repartir or sumAnt != suma) return false;
         }
      }
   }
   return true;
}

int main(){
   int casos;
   cin >> casos;
   for(int k = 1; k <= casos; ++k){
      int n, m;     
      string s; 
      cin >> n >> m;
      Matriu mat(n, vector<int>(m));
      for(int i = 0; i < n; ++i){
         for(int j = 0; j < m; ++j){
            cin >> s;
            if(s == "X") mat[i][j] = -1;
            else (stringstream)s >> mat[i][j];
         }
      }
      bool valid = posar_bishops(mat);
      if(valid) cout << "Case " << k << ": yes" << endl;
      else cout << "Case " << k << ": no" << endl;
   }
}
