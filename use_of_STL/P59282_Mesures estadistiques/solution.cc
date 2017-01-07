#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
    priority_queue<int,vector<int>,greater<int> > q;
    string s;
    int numeros = 0;
    int min, max;
    int suma = 0;
    double average;
    cout.setf(ios::fixed);
    cout.precision(4);
    while (cin >> s) {
	if (s == "number") {
	    int x;
	    cin >> x;
	    if (numeros == 0) max = min = x;
	    if (q.empty()) max = x;
	    q.push(x);
	    if (x > max) max = x;
	    if (x < min) min = x;
	    ++numeros;
	    suma += x;
	    average = double(suma)/numeros;
	    cout << "minimum: " << min << ", maximum: " << max << ", average: " << average << endl;
	}
	else if (s == "delete") {
	    if (not q.empty()) {
		if (numeros == 1) {
		    int borrar = q.top();
		    suma -= borrar;
		    q.pop();
		    cout << "no elements" << endl;
		    average = double(suma)/numeros;
		    --numeros;
		    min = max = 0;
		}
		else {
		    int borrar = q.top();
		    suma -= borrar;
		    --numeros;
		    q.pop();
		    min = q.top();
		    average = double(suma)/numeros;
		    cout << "minimum: " << min << ", maximum: " << max << ", average: " << average << endl;
		}
	    }
	    else cout << "no elements" << endl;
	}
    }
}