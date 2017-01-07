#include<iostream>
#include<vector>
#include<string>
using namespace std;

void write(const vector<int>& vistos, const vector<char>& con, const vector<char>& voc) {
    for (int i = 0; i < vistos.size(); i+=2) {
        cout << con[vistos[i]] << voc[vistos[i+1]];
    }
    cout << endl;
}

void backtrack(int q, const vector<char>& con, const vector<char>& voc, vector<int>& vistos, vector<bool>& encon, vector<bool>& envoc) {
    if (q == vistos.size()) write(vistos,con,voc);
    else {
        if (q%2 == 0) {     // consonant
            for (int i = 0; i < con.size(); ++i) {
                if (not encon[i]) {
                    encon[i] = true;
                    vistos[q] = i;
                    backtrack(q+1,con,voc,vistos,encon,envoc);
                    encon[i] = false;
                }
            }
        }
        else {              // vocal
            for (int i = 0; i < voc.size(); ++i) {
                if (not envoc[i]) {
                    envoc[i] = true;
                    vistos[q] = i;
                    backtrack(q+1,con,voc,vistos,encon,envoc);
                    envoc[i] = false;
                }
            }
        }
    }
}

int main() {

    // 3
    // mpt c(n)
    // aeo v(n)

    int n;
    cin >> n;
    vector<char> con(n);                         // consonants
    vector<char> voc(n);                         // vocals
    for (int i = 0; i < n; i++) cin >> con[i];
    for (int i = 0; i < n; i++) cin >> voc[i];

    vector<int> vistos(2*n);
    vector<bool> encon(n,false);
    vector<bool> envoc(n,false);
    backtrack(0,con,voc,vistos,encon,envoc);
}
