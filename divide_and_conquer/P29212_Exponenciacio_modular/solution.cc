#include<iostream>
using namespace std;

int modular_exponentation(int n, int k, int m) {
    if (k == 0) return 1;
    if (k % 2 != 0) return (n%m*modular_exponentation(n,k-1,m))%m;
    int ret = modular_exponentation(n,k/2,m)%m;
    return (ret*ret)%m;
}

int main() {
    int n, k, m;
    while (cin >> n >> k >> m) {
	cout << modular_exponentation(n,k,m) << endl;
    }
}