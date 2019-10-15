#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/Kattis-amanda

const int MAX  = 200005;
vector<int> g [MAX];
int color[MAX];
bool visited [MAX], visited2[MAX];
set<pair<int, pair<int, int> > > neighbors;
set<int>e_1, e_0;
bool bipartite;
int N,M;
int cont;

bool exc; int ini;

void dfs(int u){
    visited[u]= true;
    if(!exc && color[u]!=-1){
    	exc=true;
    	ini = u;
    }
    for(int i = 0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!visited[v])dfs(v);
    }

}

void bfs(int u){
	int total=0, unos=0;
    queue<int>q;
    q.push(u);
    if(!exc)color[u]=0;
    visited2[u]=1;
    
    while(q.size()){
        u = q.front();
        q.pop();
        visited2[u]=1;
        if(exc){ 
        	cont+=color[u];
        }else{
        	unos+=color[u];
        	total++;
        }
        for(int i = 0; i<g[u].size(); i++){
			
            int v = g[u][i];
            if( color[v] == -1){
                color[v]= color[u]^1;
            }
            else if(color[v] == color[u]){
            	if(!neighbors.count(make_pair(v, make_pair(u, color[v])))){
            		 bipartite = false; return;	
                }
            }
            if(!visited2[v])q.push(v), visited2[v]=1;
        }
    }
    
    if(!exc){
    	cont+= min(unos, total-unos);
    }
    
}

void init(){
    ini =0;
    bipartite = true; cont = 0;
    for(int i =0; i<=N; i++){
        g[i].clear();
        color[i]= -1;
        visited[i]=0;
        visited2[i]=0;
    }

}

int main(){
    #ifdef LOCAL
        freopen("a.txt","r",stdin);
    #endif

    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
        cin>>N>>M;
        init();
        
        int a,b,c;
        
        while(M--){
        	
            cin>>a>>b>>c;
            
            a--; b--;
            if(c==0){
                if(e_1.count(a) || e_1.count(b)) bipartite=false;
            	neighbors.insert(make_pair(a,make_pair(b,0)));
            	neighbors.insert(make_pair(b,make_pair(a,0)));
                color[a]=0; color[b]=0;
                e_0.insert(a);
                e_0.insert(b);
            }else if(c==2){
                if(e_0.count(a) || e_0.count(b)) bipartite=false;
            	neighbors.insert(make_pair(a,make_pair(b,1)));
            	neighbors.insert(make_pair(b,make_pair(a,1)));
                color[a]=1; color[b]=1;
                e_1.insert(a);
                e_1.insert(b);
            }
                g[a].push_back(b);
                g[b].push_back(a);

            
        }
        for(int i =0; i<N && bipartite; i++){
        	
            if(!visited[i]){
                exc= false;
            //verificar si el color de ese subgrafo es-1 en todos los nodos
                dfs(i);
                if(!exc){
                    bfs(i);
                    if(!bipartite) break;
                }else{
                    bfs(ini);
                    if(!bipartite) break;
                }
            }
        }


        if(!bipartite)cout<<"impossible"<<endl;
        else{
            cout<<cont<<endl;
        }

    return 0;
}
