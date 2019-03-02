#include <bits/stdc++.h>
using namespace std;
//https://www.urionlinejudge.com.br/judge/es/problems/view/1082
 
int v, e; //vertices, arcos
const int MAX=100005; //Cantidad máxima de nodos del grafo
vector<int> ady[MAX]; //lista de Adyacencia del grafo
int marked[MAX]; //Estructura auxiliar para marcar los nodos ya visitados
int m=1;

/*Debe llamarse al iniciar cada caso de prueba luego de haber leido v
Limpia todas las estructuras de datos.*/
void init(){
    
	for(int j = 0; j <= v; j++) {
    marked[j] = 0;
    ady[j].clear();
  }
}

/*Este método se llama con el indice del nodo desde el que se desea comenzar
el recorrido.*/
static void dfs(int s){
      //    char r=(char)s+97;
      //    cout<<r<<",";
	marked[s] = m;
	int i, next;

	for( i = 0; i < ady[s].size(); i++ ){
		next = ady[s][i];
                
		if( marked[next] == 0 ){
                  
              
			dfs(next);
		}
	}
}
 
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ca;
    cin>>ca;
      int t=1;
    while(ca-->0){
        init();
    cin>>v>>e;
    
    char a, b;
  
    int wa=e;
    while(wa-->0){
        cin>>a>>b;
        
        int p, f;
        p=(int)a-97;
        f=(int)b-97;
        ady[p].push_back(f);
        ady[f].push_back(p);
        
    }
    cout<<"Case #"<<t<<":\n";
    int com=0;
    for(int y=0; y<v; y++){
        if(marked[y]==0){
        dfs(y);
        com++;
        for(int i=0; i<v; i++){
            if(marked[i]==m){
                char ee= (char) i+97;
                cout<<ee<<",";
            }
        }
            cout<<endl;
        }
        m++;
    }
    cout<<com<<" connected components\n\n";
    t++;
   
    }
 
   
    return 0 ;
 
}




