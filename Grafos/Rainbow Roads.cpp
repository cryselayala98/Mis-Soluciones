#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair

//https://codeforces.com/gym/101615/attachments   ejercicio D

int v, e; 
const int MAX=50005; 
vector<int> ady[MAX]; 
int dist[MAX];  //<=2
set<pair<int, int> > eliminar;
map <int, pair<int, vector<int> > > rep[MAX];
int res;

static void dfs(int s, int o){
	
	
	int i, next;
	dist[s] ++;
    if(dist[s]==1)res--;
  
	for( i = 0; i < ady[s].size(); i++ ){
		next = ady[s][i];
		if( dist[next] <=2 && next!= o ){
			
		dist[next] ++;
    
        if(dist[next]==1)res--;
			
			dfs(next, s);
		}	
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int a,b,c;
	cin>>v; e = v-1;
	res=v;
	memset(dist, 0, sizeof(dist));
	while(e--){
		cin>>a>>b>>c;
		ady[a-1].push_back(b-1);
		ady[b-1].push_back(a-1);
		
		rep[a-1][c].f++;
		rep[b-1][c].f++;
	
		rep[a-1][c].s.pb(b-1);
		rep[b-1][c].s.pb(a-1);
	}
	
	for(int i =0; i<v; i++){
		for(auto x : rep[i]){
			
		if(x.s.f>1){
			for(int j = 0; j< x.s.s.size(); j++){
				eliminar.insert(mp(x.s.s[j], i));
			}
		}	
		}
	}
	
	for(auto x: eliminar){
		if(dist[x.f]<=2) dfs(x.f, x.s);
	}
	
	cout<<res<<"\n";
	for(int i = 0; i< v; i++)if(dist[i]==0) cout<<i+1<<"\n";
	
	
	return 0;
}