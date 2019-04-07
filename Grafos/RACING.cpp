#include <bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3675
 
struct edge { int src, dest, weight; };
 
const int MAXV = 100005;
 
int v, e;
 
vector<edge> edges, result;
int cheapest[MAXV]; //guarda el idx del edge de menor peso de un subconjunto
 
int dsu[MAXV]; 
int size[MAXV]; 
int numSets; 
 
void init() { 
	edges.clear(); result.clear();
	numSets = v;
	for(int i = 0; i < v; i++) {
		dsu[i] = i; size[i] = 1;
	}
}
 
void add_edge(int s, int d, int w){
 
	edge aux = edge{s,d,w};
	edges.push_back(aux);
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
	numSets--;
}
 
int boruvka(){
	int weightMST=0;
 
	while(true){
 
		for(int i =0; i<v; i++)cheapest[i]=-1;
 
		/*hallando la arista de menor peso para cada componente*/
		for (int i=0; i<e; i++){
			int represent_src = find(edges[i].src); 
			int represent_dest = find(edges[i].dest);
 
			if(represent_src!=represent_dest){ //no hacen parte del mismo conjunto
 
				if(cheapest[represent_src]==-1 || edges[i].weight > edges[cheapest[represent_src]].weight)
				cheapest[represent_src]= i;
 
				if(cheapest[represent_dest]==-1 || edges[i].weight > edges[cheapest[represent_dest]].weight)
				cheapest[represent_dest]= i;
			}
		}
 
		/*tomando en cuenta algunos arcos de cheapest[] para formar mst*/
		for (int i=0; i<v; i++){
 
			if (cheapest[i] == -1) continue; 
 
			int represent_src = find(edges[cheapest[i]].src); 
			int represent_dest = find(edges[cheapest[i]].dest);
 
			if(represent_src!=represent_dest){ 
 
				weightMST+= edges[cheapest[i]].weight;
				unite(represent_src, represent_dest);
				result.push_back(edges[cheapest[i]]);
				if(numSets==1) return weightMST;
			}
		}
	}	
}
 

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int t; cin>>t; int final;
	while(t--){
		cin>>v>>e;
		init();
		int a,b,c; int sum=0;
		for(int i = 0; i<e; i++){
			cin>>a>>b>>c;
			add_edge(a-1,b-1,c);
			sum+=c;
		}
		int mst= boruvka();
		cout<<sum-mst<<endl;
	
	}
	cin>>final;
	return 0;
}