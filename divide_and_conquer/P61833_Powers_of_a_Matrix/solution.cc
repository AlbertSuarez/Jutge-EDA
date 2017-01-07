#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriu;

void llegir(Matriu& a) {
    int n = 2;
    a = Matriu (n, vector<int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }
}

void escriure (const Matriu& a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[0].size(); ++j) {
            if (j == 0) cout << a[i][j];
            else cout << " " << a[i][j];
        }
        cout << endl;
    }
}

Matriu mult(Matriu &a, Matriu &b, int m){
    Matriu aux;
    aux = Matriu (2,vector<int> (2));
    aux[0][0] = (a[0][0]*b[0][0]+a[0][1]*b[1][0])%m;
    aux[0][1] = (a[0][0]*b[0][1]+a[0][1]*b[1][1])%m;
    aux[1][0] = (a[1][0]*b[0][0]+a[1][1]*b[1][0])%m;
    aux[1][1] = (a[1][0]*b[0][1]+a[1][1]*b[1][1])%m;
    return aux;
}

void exp(Matriu a, Matriu &res, int n, int m){
    Matriu aux;
    aux = Matriu (2,vector<int> (2));
    if(n == 0){
        res[0][0] = 1;
        res[1][1] = 1;
        res[0][1] = 0;
        res[1][0] = 0;
    }
    else if(n==1){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                res[i][j] = a[i][j]%m;
            }
        }
    }else if(n%2==0){
        n /= 2;
        exp(a,aux,n,m);
        res = mult(aux,aux,m);
    }else{
        n /= 2;
        exp(a,aux,n,m);
        aux = mult(aux,aux,m);
        res = mult(aux,a,m);
    }
}

int main() {
    Matriu a;
    int n, m;
    llegir(a);
    while (cin >> n >> m) {
        Matriu res (2,vector<int> (2));
        exp(a,res,n,m);
        escriure (res);
        cout << "----------" << endl;
        llegir(a);
    }
} 

