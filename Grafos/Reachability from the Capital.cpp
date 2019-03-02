#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/999/E

#define Node pair < int, long long > 
int rta;
int v, e; 
const int MAX=100005;
vector<int> ady[MAX]; 
bool marked[MAX]; 
vector<int> topoSort;
void dfs( int u ){
	int i, v;
	marked[u] = 1;
	for( i = 0; i < ady[u].size(); i++){
		v = ady[u][i];
		if( !marked[v] ) dfs(v);
	}
	topoSort.push_back(u);
}

int main(){
	
	memset(marked, 0, sizeof(marked));
	int s, d,w;
	cin>>v>>e>>w;
	w--;
	rta=0;
	while(e--){
		
  cin>>s>>d;
  s--; d--;
  ady[s].push_back(d);
 
	}
	
	dfs(w);
	int cont =0;
	for(int i =0; i<v; i++){
	if(!marked[i]){
	dfs(i);

	}	
	}
	memset(marked, 0, sizeof(marked));
	cont = topoSort.size();
	dfs(w);
	for(int i =cont; i>=0; i--){
		if(!marked[topoSort[i]]){
			rta++;
		
			dfs(topoSort[i]);
		}
	}
  
  cout<<rta<<endl;
}