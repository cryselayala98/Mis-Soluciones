#include <bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945

int main() {
	int v,e,a,b;
	 bool es_bipartito;
	int mark[205];
	set<int> net [205];
	while(cin>>v,v){
		queue <int> q; es_bipartito = 1;
		memset(mark, -1, sizeof(mark));
		for(int i = 0; i< v; i++) net[i].clear();
		cin>>e;
		while(e--){
			cin>>a>>b;
			net[a].insert(b);
			net[b].insert(a);
		}
		//bfs
		int act;
		bool color = 0;
		mark[0] = color;
		q.push(0);
		while(!q.empty()){
				act = q.front(); q.pop();
				for(auto sig : net[act]){
					if(mark[sig] == -1){
						mark[sig] = !mark[act];
						q.push(sig);
					}else if(mark[sig] == mark[act]) {es_bipartito = 0; goto final;}
				}
		}
				final:
		(es_bipartito)? cout<<"BICOLORABLE.\n" : cout<<"NOT BICOLORABLE.\n";
	}
	return 0;
}