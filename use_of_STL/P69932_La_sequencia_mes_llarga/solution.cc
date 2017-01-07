#include <sstream>
#include <iostream>
#include <set>
using namespace std;

int sequencia(set<int>& m) {
  set<int, int>::iterator it1, it2;
  int seq = 1;
  if (m.begin() == m.end() ) return 0;
  it1 = m.begin();
  it2 = it1;
  ++it2;
  if (it2 == m.end() ) return 1;
  while (it2 != m.end() ) {
    if ((*it1 + *it2)%2 != 0) ++seq;
    ++it1;
    ++it2;
  }
  return seq;
}

int main() {
  string s;
  while (getline(cin, s)) {
    istringstream ss(s);
    set<int> m;
    int x;
    while (ss >> x) m.insert(x);
    cout << sequencia(m) << endl;
  }
}
  
