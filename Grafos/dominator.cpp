#include <bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3053

int v; 
const int MAX=200;
vector<int> ady[MAX]; 
bool marked[MAX]; 


static void dfs(int s){
	marked[s] = 1;
	int i, next;

	for( i = 0; i < ady[s].size(); i++ ){
		next = ady[s][i];
		if( !marked[next] )	dfs(next);
	}
}


int main() {
	int casos, a;
	cin>>casos;
	int cas=1;
	while(casos--){
		cin >> v;
		/*clear*/
		for(int i=0; i<v; i++){
			ady[i].clear();
			marked[i] = false;
		}
		
		for(int i=0; i<v; i++){
			for(int j=0; j<v; j++){
				cin>>a;
				if(a==1)  ady[i].push_back(j);
			}
		}
		int dominator[v][v]; //1-> si, 0->no
		memset(dominator, 1, sizeof(dominator));
		dfs(0);
		for(int i=0; i<v; i++){
			if(!marked[i]) for(int j=0; j<v; j++) dominator [j][i] = 0;
			else marked[i] = false;
		}
		/*para todo x*/
		int deshabilitado;
		for(int i=1; i<v; i++){
			deshabilitado=i;
			marked[deshabilitado]=true;
			dfs(0);
			for(int j=0; j<v; j++){
				if(j!=deshabilitado && marked[j]){
					marked[j]=false;
					dominator[deshabilitado][j] = 0;
				}
			} marked[deshabilitado]=false;
		}
		cout<<"Case "<<cas<<":";
		cas++;
		int guion= 2 * v - 1 ;
		string linea="\n+";
		for(int k=0; k<guion; k++) linea+="-";
		linea+="+\n";
		for(int i=0; i<v; i++){
			cout<<linea<<"|";
			for(int j = 0; j<v; j++){
				if(dominator[i][j]==0)cout<<"N";
				else                  cout<<"Y";
				cout<<"|";
			}
		
		}cout<<linea;
	}
	return 0;
}