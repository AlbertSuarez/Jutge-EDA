#include<iostream>
#include<vector>

using namespace std;

typedef vector<pair<int, bool> > V;
//typedef Pair<string, bool> P;

void escriu (V& v, int i, int suma, int m) {
  if (i == v.size() and suma != m) return;
  if(i == v.size() and suma == m) {
      bool primer = true;
      cout << '{';
      for(int j = 0; j < v.size(); ++j) {
        if(v[j].second) {
          if(not primer) cout << ',';
          else primer = false;
          cout << v[j].first;
        }
      }
      cout << '}' << endl;
  }
  //else if ((v.size() -i) < m - cont) return;
  else {
    v[i].second = false;
    escriu(v, i+1, suma, m);
    v[i].second = true;
    escriu(v, i+1, suma+v[i].first, m);
    v[i].second = false;
  }
}

int main() {
  int m, n;
  cin >> m >> n;
  V v(n);
  for(int i = 0; i < n; ++i) cin >> v[i].first;
  escriu(v, 0, 0, m);
}
