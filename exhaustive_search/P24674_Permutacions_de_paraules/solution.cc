#include<iostream>
#include<vector>
#include<string>
using namespace std;

void write(const vector<string>& T) {
    bool primer = true;
    cout << "(";
    for (int j = 0; j < T.size(); j++) {
        if (not primer) cout << "," << T[j];
        else cout << T[j];
        primer = false;
    }
    cout << ")" << endl;
}

void backtrack(int q, const vector<string>& v, vector<string>& T, vector<bool>& posat) {
    if (q == T.size()) write(T);
    else {
        for (int i = 0; i < v.size(); ++i) {
            if (not posat[i]) {
                posat[i] = true;
                T[q] = v[i];
                backtrack(q+1,v,T,posat);
                posat[i] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    vector<bool> posat(n,false);
    vector<string> T(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    backtrack(0,v,T,posat);
}
