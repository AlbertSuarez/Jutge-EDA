#include <iostream>
#include <vector>
using namespace std;


void escriu (const vector<int>& v) {
   bool primer = true;
   cout << "(";
   for (int i = 0; i < v.size(); ++i) {
	   if (v[i] != 0) {
		   if (primer) primer = false;
		   else if (not primer) cout << ",";		 
		   cout << v[i];
	   }
   }
   cout << ")" << endl;
}

void rec (vector<int>& v, int i, int n, vector<bool>& b) { 
   if (i == n) {
      escriu(v);
   }
 	else {
      for (int f = 1; f <= n; ++f) {
		   if (not b[f-1]) {
            v[i] = f;
            b[f-1] = true;
            rec(v,i+1,n, b);
            b[f-1] = false;	
         }     
      }
	}
}

int main () {
   int num, n;
   cin >> n;
   vector<int> v(n);
   vector<bool> b(n, false);
   rec(v,0,n, b);
}
