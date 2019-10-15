#include <bits/stdc++.h>
using namespace std;

//https://juezguapa.com/concursos/concurso-interno-de-programacion-3/problemas/enunciado/enredo-azucarado
//disjoint set

set <int>en;

const int MAX = 10005; //Cantidad maxima de conjuntos disyuntos
int dsu[MAX]; //Almacena el indice del lider de cada conjunto
int size[MAX]; //Almacenar el tamano de los conjuntos
int numSets; //Cantidad de conjuntos disyuntos existentes

/** Recibe la cantidad de conjuntos disyuntos iniciales **/

void init(int n) {
	numSets = n;
	for(int i = 0; i < n; i++) {
		dsu[i] = i; size[i] = 1;
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

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n,c; cin>>n>>c;
	
	init(n);
	int a,b; 
	
	while(c--){
		cin>>a>>b;
		
		unite(a,b);
	}
	
	int total = n*(n-1);
	for(int i = 0; i<n; i++){
		int rep = find(i);
		if(!en.count(rep)){
			int cnt = sizeOf(rep);
			if(cnt>1)total-=cnt*(cnt-1);
			
			en.insert(rep);
		}
	}
	cout<<total<<endl;
	return 0;
	
}
