#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/909/problem/E

int v,e;
vector <int> ady[100005];
bool marked[100005], t_ejec[100005]; int dependencia[100005];
queue <int> procesador, coprocesador;

void dfs( int u ){
	int i, w;
	marked[u] = 1;
	for( i = 0; i < ady[u].size(); i++){
		w = ady[u][i];
		dependencia [w] ++ ; //no es inicio tarea
		if( !marked[w] ) dfs(w);
	}
	
}

void bfs(int p){ //p 0= proc 1 = cop

  int actual, i, next;
  if(!p){
  	
  while( procesador.size() > 0 ){
    actual = procesador.front();
    procesador.pop();
    for( i = 0; i < ady[actual].size(); i++){
      next = ady[actual][i];
      dependencia[next]--;
      if(!marked[next] && dependencia[next]<=0){
        marked[next] = 1;
        if(!t_ejec[next])procesador.push(next);
        else coprocesador.push(next);
      }
    }
  }
  
}else{
	
	while( coprocesador.size() > 0 ){
    actual = coprocesador.front();
   
    coprocesador.pop();

    for( i = 0; i < ady[actual].size(); i++){
      next = ady[actual][i];
      dependencia[next]--; 
      if(!marked[next] && dependencia[next]<=0){
        marked[next] = 1;
        if(!t_ejec[next])procesador.push(next);
        else coprocesador.push(next);
      }
    }
  }
	
}
}


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	cin>>v>>e;
	for(int i = 0; i<v; i++) cin>>t_ejec[i];
	
	int a,b;
	for(int i = 0; i<e; i++){
		cin>>a>>b;
		ady[b].push_back(a);
	}
	memset(marked, 0, sizeof(marked));
	memset(dependencia, 0, sizeof(dependencia));
	
	for(int i = 0; i<v; i++){
		if( !marked[i] )dfs(i);
	}
		memset(marked, 0, sizeof(marked));
		
	for(int i = 0; i<v; i++){
		if(!dependencia[i]){ //es una tarea inicial
		
			marked[i] = 1;
			if(!t_ejec[i]) procesador.push(i);
			else coprocesador.push(i);
		}
	}
	
	bool p = 1; int res = 0;
	while(coprocesador.size() || procesador.size()){
		p = (p?0:1);
		bfs(p);
		res+=p;
	}
	
	cout<<res<<endl;
	
	
	
	return 0;
}