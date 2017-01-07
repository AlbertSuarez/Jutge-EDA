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

void zerosiuns(vector<bool>& sp, int q) {
    if (q == sp.size()) write(sp);
    else {
        sp[q] = false;
        zerosiuns(sp,q+1);
        sp[q] = true;
        zerosiuns(sp,q+1);
    }
}


int main() {
    int n;
    cin >> n;
    vector<bool> sp(n);
    zerosiuns(sp,0);
}
