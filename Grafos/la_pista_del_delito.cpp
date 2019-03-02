#include <bits/stdc++.h>
using namespace std;

int v, e; 
const int MAX=1010; 
vector<int> ady[MAX]; 
bool marked[MAX]; 

bool ciclo ;
bool en;
static void dfs(int s){
	marked[s] = 1;
	int i, next;

	for( i = 0; i < ady[s].size() && !ciclo ; i++ ){
		next = ady[s][i];
		if( !marked[next] )	dfs(next);
		else {
			cout << next+1 ;
			if(!en) cout<<" ";
			ciclo = 1;
		}
	}
}

int main() {
	int a;
	while(cin>>v){
		for(int i = 0 ; i<v; i++) ady[i].clear();
		for(int i = 0; i<v; i++){
			cin>>a;
			ady[i].push_back(a-1);
		}
		en = 0;
		for(int i = 0; i<v; i++){
			if(i== v-1)  en = 1;
			memset(marked, 0, sizeof(marked));
			ciclo = 0;
			dfs(i);
		}
		cout<<endl;
	}
	return 0;
}