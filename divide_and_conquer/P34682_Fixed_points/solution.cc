#include<iostream>
#include<vector>
using namespace std;

int fixed_points(vector<int>& v, int a, int esq, int dre) {
    if (esq > dre) {
      return -1;
    }
    else {
	int pos = (dre + esq)/2;
	if (v[pos] < pos + 1 - a) return fixed_points(v,a,pos+1,dre);
	else if (v[pos] > pos + 1 - a) return fixed_points(v,a,esq,pos-1);
	else if (pos > 0 and v[pos-1] == pos - a) return fixed_points(v,a,esq,pos-1);
	else return pos + 1;
    }
}

void llegir_vector(vector<int>& v) {
    int n = v.size();
    for (int j = 0; j < n; ++j) {
	cin >> v[j];
    }
}

int main() {
    int cont = 0;
    int n;
    while (cin >> n) {
	++cont;
	vector<int> v(n);
	llegir_vector(v);
	int m,a;
	cin >> m;
	cout << "Sequence #" << cont << endl;
	for (int i = 0; i < m; ++i) {
	    cin >> a;
	    int ret = fixed_points(v,a,0,n);
	    if (ret == -1) cout << "no fixed point for " << a << endl;
	    else cout << "fixed point for " << a << ": " << ret << endl;
	}
	cout << endl;
    }
}