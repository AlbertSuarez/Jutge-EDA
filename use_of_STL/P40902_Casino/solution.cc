#include <iostream>
#include <map>
using namespace std;


void enter(string s, map <string, int> &casino)
{
	map <string, int>::iterator it;
	it = casino.find(s);
	if (it == casino.end()) casino.insert(pair<string, int> (s, 0));
	else cout << s << " is already in the casino" << endl;
}

void win (string s, int n, map <string, int> &casino)
{
	map <string, int>::iterator it;
	it = casino.find(s);
	if (it == casino.end()) cout << s << " is not in the casino" << endl;
	else 
	{
		it->second = it->second + n;
	}
}

void leaves (string s, map <string, int> &casino)
{
	map <string, int>::iterator it;
	it = casino.find(s);
	if (it == casino.end()) cout << s << " is not in the casino" << endl;
	else 
	{
		cout << s << " has won " << it->second << endl;
		casino.erase(s);
	}
}

int main() {
	map <string, int> casino;
	string s, t;
	while(cin >> s >> t) 
	{
		if (t == "enters") enter(s, casino);
		else if (t == "leaves") leaves(s, casino);
		else if (t == "wins")
		{
			int n;
			cin >> n;
			win(s, n, casino);			
		}
	}
	cout << "----------" << endl;
	map <string, int>::iterator it;
	it = casino.begin();
	while (it != casino.end())
	{
		cout << it->first << " is winning " <<it ->second << endl;
		++it;
	}
}
