#include <iostream>
#include <vector>
using namespace std;


void escriu (const vector<int>& v, const vector<int>& s) {
   bool primer = true;
   cout << "{";
   for (int i = 0; i < v.size(); ++i) {
	   if (v[i] != 0) {
		   if (primer) primer = false;
		   else if (not primer) cout << ",";		 
		   cout << s[i];
	   }
   }
   cout << "}" << endl;
}

void rec (vector<int>& v, int i, int n, const vector<int>& s, int num, int suma, int total) { 
   if (i == n) {
      if (suma == num) escriu(v,s);
   }
 	else if (suma <= num and suma + total >= num) {
			v[i] = 0;
         rec(v,i+1,n,s,num,suma, total-s[i]);	
         v[i] = 1;
         rec(v,i+1,n,s,num,suma+s[i], total-s[i]);
	}
}

int main () {
   int num, n;
   cin >> num >> n;
   vector<int> c(n);
   vector<int> v(n);
   int total = 0;
   for (int i = 0; i < n; ++i) {
      cin >> c[i];
      total += c[i];
   }
   if(total >= num) rec(v,0,n,c,num,0, total);
}
