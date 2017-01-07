#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
typedef map<string,int> MSI;
typedef vector<string>  VS;
typedef vector<bool>    VB;
typedef vector<int>     VI;
typedef vector<VI>      VVI;
 
int n_outputs, n_inputs;
VVI gdir, ginv;
MSI s2v;
VS  v2s;
 
int string2vertex(const string& s) {
  map<string,int>::iterator i = s2v.find(s);
  if (i != s2v.end())
    return i->second;
  else {
    int v = v2s.size();
    v2s.push_back(s);
    s2v.insert(make_pair(s, v));
    return v;
  }
}
 
int main() {
 
  n_outputs = n_inputs = 0;
 
  string token;
 
  cin >> token;
  while (cin >> token and token != "END") {
    ++n_outputs;
    string2vertex(token);
  }
 
  cin >> token;
  while (cin >> token and token != "END") {
    ++n_inputs;
    string2vertex(token);
  }
 
  while (cin >> token and token != "END") {
 
    string s;
    cin >> s;
    int ov = string2vertex(s);
    if (ov+1 > gdir.size()) gdir.resize(ov+1);
 
    cin >> s;
    int iv1 = string2vertex(s);
    if (iv1 + 1 > ginv.size()) ginv.resize(iv1 + 1);
 
    if (token == "NOT") {
      gdir[ov ].push_back(iv1);
      ginv[iv1].push_back(ov );
    }
    else {
      cin >> s;
      int iv2 = string2vertex(s);
      if (iv2 + 1 > ginv.size()) ginv.resize(iv2 + 1);
      if (token == "AND") {
        gdir[ov].push_back( min(iv1,iv2) );
        gdir[ov].push_back( max(iv1,iv2) );
      }
      else {
        gdir[ov].push_back( max(iv1,iv2) );
        gdir[ov].push_back( min(iv1,iv2) );
      }
      ginv[iv1].push_back(ov);
      ginv[iv2].push_back(ov);
    }
  }
 
  int n = gdir.size();
  VI ddir(n, 0);
  for (int v = 0; v < n; ++v)
    ddir[v] = gdir[v].size();
 
  VI bag;
  for (int v = n_outputs; v < n_inputs + n_outputs; ++v)
    bag.push_back(v);
 
  VI ord;
  while (not bag.empty()) {
    int v = bag.back();
    ord.push_back(v);
    bag.pop_back();
    for (auto w : ginv[v]) {
      --ddir[w];
      if (ddir[w] == 0)
        bag.push_back(w);
    }
  }
 
  VB val(n);
  while (cin >> token) {
    val[ n_outputs ] = (token == "T");
    for (int v = n_outputs+1; v < n_inputs + n_outputs; ++v) {
      cin >> token;
      val[v] = (token == "T");
    }
 
    for (auto v : ord) {
      if (gdir[v].size() == 1) {
        val[v] = not val[gdir[v][0]];
      }
      else if (gdir[v].size() == 2) {
        int iv1 = gdir[v][0];
        int iv2 = gdir[v][1];
        if (iv1 < iv2) val[v] = val[iv1] and val[iv2];
        else           val[v] = val[iv1]  or val[iv2];
      }
    }
    cout << (val[0] ? 'T' : 'F');
    for (int v = 1; v < n_outputs; ++v)
      cout << ' ' << (val[v] ? 'T' : 'F');
    cout << endl;
  }
}