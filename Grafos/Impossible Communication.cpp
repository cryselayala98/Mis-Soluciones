#include <bits/stdc++.h>
using namespace std;

/*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5225*/

int v, e; 
const int MAX = 50005; // Máxima cantidad de nodos
int dfs_low[MAX];
int dfs_num[MAX];
bool marked[MAX];
vector<int> s;
int dfsCont, cantSCC;
vector<int> ady[MAX];

void init() {
    cantSCC = 0; //Tarjan
   
    for( int j = 0; j <= v; j++ ) {
        ady[j].clear(); //Lista de Adyacencia
        marked[j] = 0; //Estructura auxiliar para marcar los nodos ya visitados
        dfs_num[j] = -1;
        dfs_low[j] = 0;
    }
}
	
void tarjanSCC( int u ){
	dfs_low[u] = dfs_num[u] = dfsCont;
	dfsCont++;
	s.push_back(u);
	marked[u] = true;
		
	int j, v;
		
	for( j = 0; j < ady[u].size(); j++ ){
		v = ady[u][j] ;
			
		if( dfs_num[v] == -1 ){
			tarjanSCC( v );
		}
			
		if( marked[v] ){
			dfs_low[u] = min( dfs_low[u], dfs_low[v] );
		}
	}
		
	if( dfs_low[u] == dfs_num[u] ){
		cantSCC++;
		/*
        /* ********************************************************* */
        /* Esta seccion se usa para imprimir las componentes conexas 
		cout << "COMPONENTE CONEXA #" << cantSCC << "\n";
		while( true ){
			v = s.back();
			s.pop_back();
			marked[v] = false;
			cout << v << " ";
			if( u == v ) break;
		}
		cout<<endl;
        ********************************************************** */
        
	}	
}

int main (){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int a,b,c,d;
	while(cin>>v>>e){
	    init();
	    while(e--){
	    	cin>>a>>b>>c;
	    	if(a==1) {
	    		ady[b-1].push_back(c-1);
	    	}else if(a==2){
	    		ady[b-1].push_back(c-1);
	    		ady[c-1].push_back(b-1);
	    	}else{
	    		a-=2;
	    		ady[b-1].push_back(c-1);
	    		while(a--){
	    			cin>>d;
	    			ady[c-1].push_back(d-1);
	    			c=d;
	    		}
	    		ady[c-1].push_back(b-1);
	    	}
	    }
	    for( int i = 0; i < v; i++ ){ //Por si el grafo no es conexo
	        if( dfs_num[i] == -1 ){
	            dfsCont = 0;
	            s.clear();
	            tarjanSCC(i);
	    	   }
	    	}
	    	if(cantSCC>1)cout<<"NO\n";
	    	else	 cout<<"YES\n";
	    	
	    }
}