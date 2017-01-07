#include<iostream>
#include<vector>
#include<string>
using namespace std;

void write(const vector<string>& v, const vector<int>& T, int p) {
    for (int i = 1; i <= p; i++) {
        bool primer = true;
        cout << "subconjunt " << i << ": {";
        for (int j = 0; j < T.size(); j++) {
            if (T[j] == i) {
                if (not primer) cout << "," << v[j];
                else cout << v[j];
                primer = false;
            }
        }
        cout << "}" << endl;
    }
}

void backtrack(int q, vector<string>& v, vector<int>& T, int p) {
    if (q == T.size()) {write(v,T,p); cout << endl;}
    else {
        for (int i = 1; i <= p; ++i) {
            T[q] = i;
            backtrack(q+1,v,T,p);
        }
    }
}

int main() {
    int n,p;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> p;
    vector<int> T(n);
    backtrack(0,v,T,p);
}
