#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define nodo pair<int, long long>

//https://codeforces.com/problemset/gymProblem/100814/D

const int MAX = 100005;
typedef long long ll;
int v;
vector<nodo>ady[MAX];
vector<pair <long long, int> >  arbol [MAX] ;
vector<long long> terminales;

long long dist[MAX]; 


void bfs(int s){
  int cont = 0;
  terminales.pb(0);
  terminales.pb(1e13);
  queue<nodo> q;
  q.push(mp(s,0)); 
  dist[s] = 0;
  nodo actual, next; int i ;
       
  while( q.size() > 0 ){
    actual = q.front();
    q.pop();
	if(ady[actual.f].size() == 0){ //hoja
		terminales.pb(dist[actual.f]);
	}
    for( i = 0; i < ady[actual.f].size(); i++){
      next = ady[actual.f][i];
      if( dist[next.f] == -1 ){
        dist[next.f] = dist[actual.f] + next.s;
        q.push(next);
      }
    }
  }

}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
   
    int t,padre; long long a; cin>>t;

	while(t--){
		cin>>v;
		terminales.clear();
		memset(dist, -1, sizeof(dist));
		for(int i = 0; i<v; i++){ady[i].clear(); arbol[i].clear();}
		for(int i = 1; i<v; i++){
			cin>>padre>>a;
			padre--;
			arbol[padre].pb(mp(a,i));
		}
		
		//formar grafo
		for(int i = 0; i<v; i++){
			
			if(arbol[i].size()>0){ //no es hoja
				sort(arbol[i].begin(), arbol[i].end());
				long long ant = arbol[i][0].f;
				ady[i].pb(mp(arbol[i][0].s, ant));
				long long d = 2;
				for(int j =1; j<arbol[i].size(); j++){
					ant = arbol[i][0].f + (arbol[i][j].f - arbol[i][0].f) * 2 ;
					ady[i].pb(mp(arbol[i][j].s, ant));
				}
			}
		
		}
		bfs(0);
		
		//consultas
		int q; cin>>q; sort(terminales.begin(), terminales.end());
		while(q--){
			cin>>a;
			vector<long long>::iterator aux =  upper_bound(terminales.begin(), terminales.end(), a);
			int pos = (aux - terminales.begin()); 
			if(terminales[pos]>a) pos--;
	
			cout<<pos<<"\n";
		}
		
		
	}
    return 0;
}


