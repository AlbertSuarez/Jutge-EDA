#include <map>
#include <iostream>
using namespace std;

int main() {
  map<string, int> m;
  map<string,int>::iterator itmin, itmax, it;
  string s;
  while (cin >> s) {
	if (s == "minimum?") {
	  itmin = m.begin();
	  if(itmin == m.end()) cout << "indefinite minimum" << endl;
	  else cout << "minimum: " << itmin->first << ", " << itmin->second << " time(s)" << endl;
	}
	else if (s == "store") {
	  cin >> s;
	  ++m[s];
	}
	else if (s == "maximum?") {
	  itmax = m.end();
	  if (m.size() == 0) cout << "indefinite maximum" << endl;
	  else {
		--itmax;
		cout << "maximum: " << itmax->first << ", " << itmax->second << " time(s)" << endl;
	  }
	}
	else if (s == "delete") {
	  cin >> s;
	  it = m.find(s);
	  if (it != m.end()) {
		--(it->second);
		if (it->second == 0) m.erase(it);
	  }
	}
  }
}
