#include <bits/stdc++.h>
using namespace std;
/*https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4648*/

vector<int> ady[1010];
int marked[1010];
int previous[1010];
int dfs_low[1010];
int dfs_num[1010];
int n, e;
int dfsRoot,rootChildren,cont;
vector< pair<int,int> > bridges;

void init() {
    
    cont = dfsRoot = rootChildren = 0; //Puentes
    bridges.clear(); //Puentes

    for( int j = 0; j <= n; j++ ) {
        
        ady[j].clear(); //Lista de Adyacencia
        marked[j] = 0; //Estructura auxiliar para marcar los nodos ya visitados
        previous[j] = -1;  //Estructura auxiliar para almacenar las rutas
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
            
            if( u == dfsRoot )  rootChildren++;
            dfs(v);
            if( dfs_low[v] > dfs_num[u] ) bridges.push_back(make_pair(min(u,v),max(u,v)));

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }else if( v != previous[u] )  dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>e;
    while(n!=0 && e!=0){
    init();
    int a,b;
    for(int i=0; i<e; i++){
    	cin>>a>>b;
    	ady[a].push_back(b);
    	ady[b].push_back(a);
    }
    dfs(dfsRoot);
    sort(bridges.begin(), bridges.end());
    cout<<bridges.size();
    for(int i=0; i<bridges.size(); i++){
    	cout<<" "<<bridges[i].first<<" "<<bridges[i].second;
    } cout<<endl;
   cin>>n>>e; }
    
    return 0;
}
