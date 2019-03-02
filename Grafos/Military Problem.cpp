#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1006/problem/E

int v, e; 
const int MAX=200005; 
set<int> ady[MAX]; 
bool marked[MAX]; 
map<int, long long>orden;
vector<long long> aux;

int init; int vec[MAX];
static void dfs(int s){
	vec[s]=1;
	orden[s]= init;
	aux.push_back(s);
	init++;
	marked[s] = 1;
	int i;
	
	for( auto next: ady[s]){
		if( !marked[next] ){
			dfs(next);
			vec[s]+= vec[next];
		}	
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	init = 1;
	memset(marked, 0, sizeof(marked));
	memset(vec, 0, sizeof(vec));
	int q;
	cin>>v>>q;
	e = v;
	int a;
	for(int i = 1; i<e; i++){
		cin>>a; a--;
		ady[a].insert(i);
	}
	long long u,k;
	aux.push_back(-100);
	dfs(0);
	
	while(q--){
		cin>>u>>k; u--;
		int pos = orden[u];
		if(k>vec[u])cout<<-1<<endl;
		else cout<<aux[pos-1+ k]+1<<endl;
	}
	return 0;
}