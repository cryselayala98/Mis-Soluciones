#include <bits/stdc++.h>
using namespace std;
#define mp make_pair 
#define f first
#define s second
/*https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=749*/

int v, e; 
const int MAX=10005; 
long long dist[MAX]; 
int diago[500][500];
pair <int , int> r [10005];



void llenar_cuadrilla(int ai, int aj, int num){
	diago[ai+1][aj+1] = num;
	diago[ai][aj]     = num;
	diago[ai+1][aj]   = num;
	diago[ai][aj+1]   = num;
}

void llenar_hexagono(){
	
	//llenar cuadricula
	int i = 250, j = 250;
	
	int seq = 0;
	int rep = seq;
	int actual = 1;
	llenar_cuadrilla (i,j, actual);
	r[actual] = mp(i,j);
	int estado = 7;
	
	while(true){
		if(estado == 7){
			estado = 1;
			seq ++;
			rep = seq-1;
			//bajar 1 pos
			actual ++;
			i += 2; 
			llenar_cuadrilla (i,j, actual);
			r[actual] = mp(i,j);
		}else rep = seq;
		
		while(rep--){
			if(actual >= 10005) return;
			//reubicar
			if(estado == 1)       i+=1, j-=2;
			else if (estado == 2) i-=1, j-=2;
			else if (estado == 3) i-=2;
			else if (estado == 4) i-=1, j+=2;
			else if (estado == 5) i+=1, j+=2;
			else if (estado == 6) i+=2;
			
			actual++;
			llenar_cuadrilla (i,j, actual);
			r[actual] = mp(i,j);
		}
		estado++;
	}
}

void bfs(int s){
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	
	q.push(r[s]);
	dist[s] = 0;
	
	pair<int, int> actual, next;
       
	  while( q.size() > 0 ){
	    actual = q.front();
	    q.pop();
	    
	    for(int k = 1; k <= 6 ; k++){
	    	
	    		if(k == 1)   next = mp(actual.f+1, actual.s-2);
			else if (k == 2) next = mp(actual.f-1, actual.s-2);
			else if (k == 3) next = mp(actual.f-2, actual.s);
			else if (k == 4) next = mp(actual.f-1, actual.s+2);
			else if (k == 5) next = mp(actual.f+1, actual.s+2);
			else if (k == 6) next = mp(actual.f+2, actual.s);
			
	      if(diago[next.f][next.s] == 0) continue;
	      
	      if( dist[diago[next.f][next.s]] == -1 ){
	        dist[diago[next.f][next.s]] = dist[diago[actual.f][actual.s]] + 1;
	        q.push(next);
	      }
	    }
	  }
	
}

int main() {
	memset(diago, 0, sizeof(diago));
	llenar_hexagono();
	int i,j;
	while(cin>>i>>j){
		if(i==0 && j==0) break;
		bfs(i);
		cout<<"The distance between cells "<<i<<" and "<<j<<" is "<<dist[j]<<"."<<endl;
	}
	
	
	return 0;
}