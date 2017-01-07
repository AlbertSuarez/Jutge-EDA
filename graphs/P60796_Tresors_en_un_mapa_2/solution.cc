#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector< vector<char> > Mapa;
typedef pair<int,int> par;
typedef pair<par,int> Coord;
#define inf 0x7fffffff

bool dl(Mapa& m,int x, int y){
	return not (x < 0 or x >= m.size() or y < 0 or y >= m[0].size() );
}

int found(Mapa& m,int x,int y){
	int rows 	= m.size();
	int columns	= m[0].size();	
	queue<Coord> Q;
	Q.push( Coord(par(x,y),0) );
	int ret = inf;
	while( not Q.empty() ){
		Coord v = Q.front();
		Q.pop();
		if(v.second > ret) break;
		if(m[v.first.first][v.first.second] == 't') if(v.second<ret) ret = v.second;
		m[v.first.first][v.first.second]='X';
		int esq = v.first.first-1;
		int dre = v.first.first+1;
		int ada = v.first.second-1;
		int aba = v.first.second+1;

		if(dl(m,esq,v.first.second) ) if(m[esq][v.first.second]!='X') Q.push( Coord( par(esq,v.first.second), v.second+1 ) );
		if(dl(m,dre,v.first.second) ) if(m[dre][v.first.second]!='X') Q.push( Coord( par(dre,v.first.second), v.second+1 ) );
		if(dl(m,v.first.first,ada) )  if(m[v.first.first][ada]!='X')  Q.push( Coord( par(v.first.first,ada), v.second+1 ) );
		if(dl(m,v.first.first,aba) )  if(m[v.first.first][aba]!='X') Q.push( Coord( par(v.first.first,aba), v.second+1 ) );

	}
	return ret;
}

int main(){

	int n,m;
	cin >> n >> m;
	Mapa mapt(n, vector<char>(m) );
	for(int i = 0; i < n ; ++i)
		for(int j = 0; j < m; ++j)
			cin >> mapt[i][j];

	cin >> n >> m;
	int dmin = found(mapt,n-1,m-1);
	if( dmin != inf )
		cout << "distancia minima: " << dmin << endl;
	else
		cout << "no es pot arribar a cap tresor" << endl;
}



				;;;;;		;;;;;
				;;;;;		;;;;;
		;;;;;						;;;;;
		  ;;;;;					      ;;;;;
		    ;;;;;				    ;;;;;
		      ;;;;;			          ;;;;;
		      	;;;;;			        ;;;;;
			  ;;;;;                       ;;;;;
			    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
					;;	     ;;
				        ;;	     ;;
					;;           ;;
					 ;;	    ;;
					  ;;       ;;
					   ;;;;;;;;;
