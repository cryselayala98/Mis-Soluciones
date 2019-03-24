#include <bits/stdc++.h>
using namespace std;

//https://www.codechef.com/problems/ICL16A

const int MAXN = 2005;
const int MAXE = 2000010;
int n, e;

struct edge { int u, v, w; };

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

edge arcos[MAXE];

int dsu[2005]; 
int size[2005]; 

void init() {
	for(int i = 0; i <= n; i++ ) {
		dsu[i] = i; size[i] = 1;
	}
}

int find(int i) {
	return (dsu[i] == i) ? i : (dsu[i] = find(dsu[i]));
}

void unite(int a, int b) {
	a = find(a); b = find(b);
	if(a == b) return;
	if (size[a] > size[b]) swap(a, b);
	dsu[a] = b;
	size[b] += size[a];
}

int kruskal() {
	//cout<<e<<endl;
	sort(arcos, arcos+e, cmp);
	edge cur; int maxi=0;
	for (int i = 0, sz = 0; i < e && sz < n-1; i++) {
		cur = arcos[i];
		if(find(cur.u) != find(cur.v)) {
			unite(cur.u, cur.v);
			maxi = max(maxi, cur.w);
			sz++;
		}
	}
	return maxi;
}

int main() {
	
	int m; cin>>n>>m; e = ((n-1)*(n))/2;
	int grid[n][m];
	string a;
	
	for(int i=0; i<n; i++){
		cin>>a;
		for(int j =0; j<m; j++){
			grid[i][j]= a[j]-'a';
		}
	}
	

	init();
	int n_arco=0;
	//definir lista de arcos
	for(int i =0; i<n-1; i++){
		for(int j =i+1; j<n; j++){
			
			int maxi=0;
			for(int k =0; k<m; k++)maxi = max(maxi, abs(grid[i][k]-grid[j][k]));
			edge dist= {i,j,maxi};
			arcos[n_arco] = dist;
			n_arco++;
		}
	}
	
	
	cout<<kruskal()<<endl;
	
	return 0;
}