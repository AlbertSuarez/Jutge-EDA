#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Fila;
typedef vector<Fila> Matriu;

int diag1(int n, int f, int c) {
   return n-c-1 + f;
}

int diag2(int f, int c) {
   return f+c;
}

void escriu(Matriu& m, int n) {
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cout << m[i][j];
      cout << endl;
   }
   cout << endl;
}

void reines (Matriu& r, vector<bool>& col, vector<bool>& dia1, vector<bool>& dia2, int n, int f) {
   if (f == n) {
      escriu(r, n);
   }
 	else {
      for (int c = 0; c < n; ++c) {
         int d1 = diag1(n, f, c);
         int d2 = diag2(f, c);
         if (not col[c] and not dia1[d1] and not dia2[d2]) {
            r[f][c] = 'Q';
            col[c] = true;
            dia1[d1] = true;
            dia2[d2] = true;
            reines(r, col, dia1, dia2, n, f+1);
            r[f][c] = '.';
            col[c] = false;
            dia1[d1] = false;
            dia2[d2] = false;
         }
      }  
	}
}

int main () {
   int num, n;
   cin >> n;
   Matriu reinas(n, Fila(n, '.'));
   vector<bool> col(n, false);
   vector<bool> dia1(2*n-1, false);
   vector<bool> dia2(2*n-1, false);
   reines(reinas, col, dia1, dia2, n, 0);
}
