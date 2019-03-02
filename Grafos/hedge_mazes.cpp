#include <bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3785

const int maxx = 10005;
vector<int> ady[maxx];
int marked[maxx];
int previous[maxx];
int dfs_low[maxx];
int dfs_num[maxx];
bool itsmos[maxx];
int n, e, q;
int dfsRoot,rootChildren,cont;
set< pair<int,int> > bridges;
int parent[maxx]; 
int size[maxx]; 
int cantSets; 

void init_disjoint( int n ){
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

int sizeOfSet( int i ){
    return size[ find(i) ];
}


void init_graph() {
    bridges.clear(); //Puentes

    for( int j = 0; j <= n; j++ ) {
        ady[j].clear();
        marked[j] = 0; 
        previous[j] = -1;  
        dfs_num[j] = -1;
        dfs_low[j] = 0;
    }
}

void dfs(int u){
    dfs_low[u] = dfs_num[u] = cont;
    cont++;
    marked[u] = 1; 
    int j, v;

    for(j = 0; j < ady[u].size(); j++){
        v = ady[u][j];
        if( marked[v] == 0 ){
            previous[v] = u;
            //para el caso especial 
            if( u == dfsRoot )  rootChildren++;
            dfs(v);
            
            //Bridges
            if( dfs_low[v] > dfs_num[u] ) bridges.insert(make_pair(min(u,v),max(u,v)));
            
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }else if( v != previous[u] )  dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(NULL); 
	
	int a,b;
	while(cin>>n>>e>>q, n){
		init_graph();
		cont = 0;
		
		while(e--){
			cin>>a>>b;
			ady[a-1].push_back(b-1);
			ady[b-1].push_back(a-1);
		}
		
			//detectar bridges
		for(int i =0; i<n; i++ ){
			if(!marked[i]) {
				dfsRoot = i;
				rootChildren = 0;
				dfs( dfsRoot );
			}
		}
		init_disjoint(n);
		for(auto bridge : bridges){
			unionFind(bridge.first, bridge.second);
		}
		
		
		while(q--){
			cin>>a>>b;
			if(find(a-1) == find(b-1))  cout<<"Y\n";
			else		    cout<<"N\n";
		}
		cout<<"-\n";
	}
 
    return 0;
}