#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/SCU-4339

struct edge { int u, v, w; };

bool cmp(edge a, edge b) {
	return a.w < b.w;
}
const int MAXN = 100005;
const int MAXE = 200005;
int n, e;
edge arcos[MAXE];
vector<pair<int, int> > ady[MAXN];

int dsu[MAXN]; 
int size[MAXN]; 
int numSets; 

void init() {
	numSets=n;
	for(int i = 0; i <= n; i++ ) {
		ady[i].clear();
		dsu[i] = i;
		size[i]=1;
	}
}

int find(int u) {
	return (dsu[u] == u) ? u : (dsu[u] = find(dsu[u]));
}

void unite(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	if (size[u] > size[v]) swap(u, v);
	dsu[u] = v;
	size[v] += size[u];
	
	numSets--;
}

int sizeOf(int u) { return size[find(u)]; }

int kruskall() {
	int maxi = 0;
	sort(arcos, arcos+e, cmp);
	edge cur;
	for (int i = 0, sz = 0; i < e && sz < n-1; i++) {
		cur = arcos[i];
		if(find(cur.u) != find(cur.v)) {
			unite(cur.u, cur.v);
			maxi = max(maxi, cur.w);
			ady[cur.u].push_back({cur.v, cur.w});
			ady[cur.v].push_back({cur.u, cur.w});
			sz++;
		}
	}
	return maxi;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	while(cin>>n>>e, n+e){
		init(); int a,b,c;
		for(int i = 0; i<e; i++){
			cin>>a>>b>>c;
			arcos[i] = edge{a,b,c};
			unite(a,b);
		}
		if(numSets>1)cout<<"IMPOSSIBLE"<<endl;
		else{
			init();
			cout<<kruskall()<<endl;
		}
		
	}
	
	return 0;
}
