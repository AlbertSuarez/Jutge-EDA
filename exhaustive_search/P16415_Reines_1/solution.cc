#include <iostream>
#include <vector>
using namespace std;

void reines (vector<bool>& col, vector<bool>& dia1, vector<bool>& dia2, int n, int f, int& cont) {
   if (f == n) ++cont;
 	else {
      for (int c = 0; c < n; ++c) {
         int d1 = n-c-1 + f;
         int d2 = f+c;
         if (not col[c] and not dia1[d1] and not dia2[d2]) {
            col[c] = true;
            dia1[d1] = true;
            dia2[d2] = true;
            reines(col, dia1, dia2, n, f+1, cont);
            col[c] = false;
            dia1[d1] = false;
            dia2[d2] = false;
         }
      }  
	}
}

int main () {
   int n;
   cin >> n;
   vector<bool> col(n, false);
   vector<bool> dia1(2*n-1, false);
   vector<bool> dia2(2*n-1, false);
   int cont = 0; 
   reines(col, dia1, dia2, n, 0, cont);
   cout << cont << endl;
}
