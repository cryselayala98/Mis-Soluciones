#include <bits/stdc++.h>
using namespace std;
#define nodo pair<int, pair<long long, long long> > //ady, (p_act, p_ady)
#define vec first 
#define p_act second.first
#define p_vec second.second
#define mp make_pair
#define pb push_back

//https://vjudge.net/problem/UVA-10113

int v, e; 
const int MAX=100; 
vector < nodo > ady[MAX]; 
map<string, int> vv;
pair<long long, long long> dist [MAX][MAX]; //(p_act, p_ady)
int parent[MAX]; 
int size[MAX]; 
int cantSets; 

void ini( int n ){
    cantSets = n;
    for( int i = 0; i <= n; i++ ){
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int i){
  parent[i] = ( parent[i] == i ) ? i : find(parent[i]);
  return parent[i];
}

void unionFind(int x, int y){
  x = find(x);
  y = find(y);

  if( x != y ){
      cantSets--;
      parent[x] = y;
      size[y] += size[x];
  }
}

int mcd (long long a, long long b) {
	while (b != 0){
		a %= b;
		swap(a, b);
	}
	return a;
}


void bfs(int s,int e){
  queue<int> q;
  q.push(s); 
  dist[s][s] = mp(1,1);
  int actual, next;
  int i;
  
  while( q.size() > 0 ){
    actual = q.front();
    q.pop();
	if(actual==e) return;
    for( i = 0; i < ady[actual].size(); i++){
      next = ady[actual][i].vec;
      if(dist[s][next].first == 0)  dist[s][next] = mp((dist[s][actual].first*ady[actual][i].p_act), (dist[s][actual].second*ady[actual][i].p_vec));
        long long divi = mcd(dist[s][next].first, dist[s][next].second);
        dist[s][next].first = dist[s][next].first / divi;
        dist[s][next].second = dist[s][next].second / divi;
        q.push(next);
      
    }
  }

}


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int init = 1; string a,c,e; long long b,d;
	ini(100);
	
	while(true){
		cin>>a;
		if(a==".")break;
		if(a=="!"){
			cin>>b>>a>>e>>d>>c;
			if(!vv[a])vv[a]= init;
			init++;
			if(!vv[c])vv[c]= init;
			init++;
			int divi = mcd(b,d);
			b = b/divi; d = d/divi;
			ady[vv[a]-1].pb(mp(vv[c]-1, mp(b,d)));
			ady[vv[c]-1].pb(mp(vv[a]-1, mp(d,b)));
			
			unionFind(vv[a]-1, vv[c]-1);
		}else{
			cin>>a>>e>>c;
			b = vv[a]-1;
			d = vv[c]-1;
			if(find(b)!=find(d)){
				cout<<"? "<<a<<" = ? "<<c<<endl;
			}else{
			if(!dist[b][d].first){
				bfs(b,d);
				
				cout<<dist[b][d].first<<" "<<a<<" = "<<dist[b][d].second<<" "<<c<<endl;
				}
			}
		}
	}
	return 0;
}