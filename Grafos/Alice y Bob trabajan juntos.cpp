#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

//https://trainingcenter.cloud.ufps.edu.co/problemas/333/detalle/es

int v, e; 
const int MAX = 505; 
int ady2[505][505]; 
vector< pair<int, int> > ady[MAX]; //nodo, peso
bool marked[MAX]; 
int cant_su, pmax;

void init(){
	  for( int j = 0; j <= v; j++ ) {
        ady[j].clear(); 
        marked[j] = 0; 
        for(int k = 0; k <= v; k++){
        if(j==k) ady2[j][k]=0;
        else ady2[j][k] = INF; //Warshall	
        }  
    }
}

int floydWarshall(){

   int k, i ,j;
    
    for( k = 0; k < v; k++ ){
    	if(!marked[k]) continue;
        for( i = 0; i < v; i++ ){
        	if(!marked[i]) continue;
            for( j = 0; j < v; j++ ){
            	if(!marked[j]) continue;
            	if(i!=j)ady2[i][j] = min( ady2[i][j], ( ady2[i][k] + ady2[k][j] ) );
                
            }
        }
    }
   //verificar max
   int maxi =0;
   for( k = 0; k < v; k++ ){
    	if(!marked[k]) continue;
        for( i = 0; i < v; i++ ){
        	if(!marked[i]) continue;
            for( j = 0; j < v; j++ ){
            	if(!marked[j]) continue;
            	if(ady2[i][j]!=INF)maxi = max(maxi, ady2[i][j]);
                
            }
        }
    } 
return maxi;
}

static void dfs(int s){
	cant_su++;
	marked[s] = 1;
	int i; pair<int, int>next;

	for( i = 0; i < ady[s].size(); i++ ){
		next = ady[s][i];
		if( !marked[next.first] ){
			pmax = max (pmax, next.second);
			dfs(next.first);	
		}
	}
}

int main() {
	int casos; cin>>casos;
	while(casos--){
		
	cin>>v>>e; int a,b,c;
	init();
	while(e--){
		cin>>a>>b>>c;
		ady[a-1].push_back(make_pair(b-1,c));
		ady2[a-1][b-1] = c;
		ady2[b-1][a-1] = c;
		ady[b-1].push_back(make_pair(a-1,c));
	}
	
	int cs=INF; int pm =0; vector<int>nodo_i;
	
	for(int i =0; i<v; i++){
		if(!marked[i]){
			cant_su=0; 
			dfs(i);
			if(cant_su<cs && cant_su>1){
				cs = cant_su; nodo_i.clear(); nodo_i.push_back(i);
			}else if(cant_su==cs){
				nodo_i.push_back(i);
			}
		}
		
	}
	int maxi=0;
	for(int i =0; i< nodo_i.size(); i++){
		memset(marked, 0, sizeof(marked));	
		dfs(nodo_i[i]);
		maxi = max(maxi, floydWarshall());
	}
	

	cout<<maxi<<endl;

	
	}
	return 0;
}
