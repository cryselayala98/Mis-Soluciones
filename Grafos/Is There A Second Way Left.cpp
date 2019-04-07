#include <bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1403

#define inf 100000000
struct edge { int src, dest, weight, rep; bool blocked; }; //rep para el caso de edges identicos

const int MAXV = 100005;

int v, e;

vector<edge>ady[MAXV]; //para el caso de detectar componentes conexas
vector<edge> edges; 
vector<int>result;  //almacena los indices de los edges del mst principal (edges[idx])
int cheapest[MAXV]; //guarda el idx del edge de menor peso de un subconjunto
bool marked[MAXV]; 
int dsu[MAXV];  //disjoint set
int size[MAXV]; //disjoint set
int numSets;    //disjoint set
bool tipo; //para almacenar en result en el caso de hallar el mst principal, solo se usa 1 vez

void init() { 
	edges.clear(); result.clear();
	numSets = v;
	for(int i = 0; i < v; i++) {
		dsu[i] = i; size[i] = 1; marked[i]=0;
		ady[i].clear();
	}
}

void dfs(int s){
	marked[s] = 1;
	int i; edge next;
	for( i = 0; i < ady[s].size(); i++ ){
		next = ady[s][i];
		if( !marked[next.dest] )	dfs(next.dest);
	}
}

void dfs2(int s, edge blocked){ 
	marked[s] = 1;
	int i; edge next;
	for( i = 0; i < ady[s].size(); i++ ){
		next = ady[s][i];
		if(next.rep==blocked.rep) continue; 
		if( !marked[next.dest] )	dfs2(next.dest, blocked);
	}
}

void add_edge(int s, int d, int w, int rep){
	
	edge aux = edge{s,d,w, rep};
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
			if(edges[i].blocked)continue;
			int represent_src = find(edges[i].src); 
			int represent_dest = find(edges[i].dest);
			
			if(represent_src!=represent_dest){ //no hacen parte del mismo conjunto
			
				if(cheapest[represent_src]==-1 || edges[i].weight < edges[cheapest[represent_src]].weight)
				cheapest[represent_src]= i;
				
				if(cheapest[represent_dest]==-1 || edges[i].weight < edges[cheapest[represent_dest]].weight)
				cheapest[represent_dest]= i;
			}
		}
		
		/*tomando en cuenta algunos arcos de cheapest[] para formar mst*/
		for (int i=0; i<v; i++){
			
			if (cheapest[i] == -1) continue; 
			if(edges[cheapest[i]].blocked)continue;
			
			int represent_src = find(edges[cheapest[i]].src); 
			int represent_dest = find(edges[cheapest[i]].dest);
			
			if(represent_src!=represent_dest){ 
				
				weightMST+= edges[cheapest[i]].weight;
				unite(represent_src, represent_dest);
			if(tipo)result.push_back(cheapest[i]);
				if(numSets==1) return weightMST;
			}
		}
	}	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin>>t; int c=1;
	while(t--){
		int cont=0;
		cin>>v>>e;
		init();
		cout<<"Case #"<<c<<" : ";
		c++;
		int a,b,c; 
		for(int i =0; i<e; i++){
			cin>>a>>b>>c;
			add_edge(a-1,b-1,c, cont);
			ady[a-1].push_back(edge{a-1,b-1,c, cont});
			ady[b-1].push_back(edge{b-1,a-1,c, cont});
			cont++;
		}
		
		int components=0;
		for(int i = 0; i<v; i++){
			if(!marked[i]){
				components++;
				dfs(i);
			}
		}
		if(components>1){
			cout<<"No way"<<endl;
		}else{
		  if(e==0)cout<<"No second way"<<endl;
		  else{
		  	
		  tipo=1; //tipo es para añadir cada edge del mst original, solo se una 1 vez
		  int best= boruvka();
		  tipo=0;
		  
		  bool exist=0; //existe más de 1 sola componente conexa al bloquear algun edge
		  int second_best=inf;
		  for(int i = 0; i<v-1; i++){ //tomar cada edge del mst principal , apagar y lanzar mst y hallar el minimo entre estos determina el segundo mst
		  	memset(marked, 0, sizeof(marked));
		  	components=0;
		  	
		  	//verificar si el grafo sigue conexo al bloquear un edge
			for(int j = 0; j<v; j++){
				if(!marked[j]){
					components++;
					dfs2(j, edges[result[i]]);
				}
			}
			
			if(components==1){
				edges[result[i]].blocked=1; 
				exist=1;
				
				//inicializar dsu
				numSets=v;
				for(int j = 0; j<v; j++){
				   dsu[j]=j; size[j]=0;
				}
				 
				int aux = boruvka();
				second_best=min(second_best, aux);
				edges[result[i]].blocked=0;
			}
		
		  }
		  
		  if(!exist)cout<<"No second way"<<endl;
		  else  cout<<second_best<<endl;
		  }
		}
	}
	return 0;
}