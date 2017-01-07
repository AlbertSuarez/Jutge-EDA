#include<iostream>
#include<vector>
using namespace std;

void write(const vector<bool>& sp) {
    for (int i = 0; i < sp.size(); i++) {
        if (i == sp.size()-1) cout << (sp[i] ? "1" : "0") << endl;
        else {
            cout << (sp[i] ? "1 " : "0 ");
        }
    }
}

void zerosiuns(vector<bool>& sp, int q, int u, int z) {
    if (z < 0 or u < 0) return;
    if (q == sp.size() and (z == 0 or u == sp.size())) write(sp);
    else {
        sp[q] = false;
        zerosiuns(sp,q+1,u,z-1);
        sp[q] = true;
        zerosiuns(sp,q+1,u-1,z);
    }
}


int main() {
    int n,u;
    cin >> n >> u;
    vector<bool> sp(n);
    zerosiuns(sp,0,u,n-u);
}
