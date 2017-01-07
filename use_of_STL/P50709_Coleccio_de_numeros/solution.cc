#include <iostream>
#include <queue>
using namespace std;

int main() {
    char c;
    int x;
    priority_queue<int> q;
    while (cin >> c) {
        if (c == 'S') {
            cin >> x;
            q.push(x);
        }
        else if (c == 'A') {
            if (q.empty()) cout << "error!" << endl;
            else cout << q.top() << endl;
        }
        else if (c == 'R') {
            if (q.empty()) cout << "error!" << endl;
            else q.pop();
        }
        else if (c == 'I') {
            cin >> x;
            if (q.empty()) cout << "error!" << endl;
            else {
		          int aux = q.top();
		          q.pop();
		          aux += x;
		          q.push(aux);
            }
        }
        else if (c == 'D') {
            cin >> x;
            if (q.empty()) cout << "error!" << endl;
            else {                
		          int aux = q.top();
		          q.pop();
		          aux -= x;
                q.push(aux);
            }
        }
    }
}
