#include <iostream>
using namespace std;
#define inf 1000000000
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1454*/

int ady[105][105];
int v,e;


int floyd_warshall(){
	
	for(int k = 0; k < v; k++){
		 for(int i = 0; i < v; i++){
    		 for(int j = 0; j < v; j++){
    			  ady[i][j] = min(ady[i][j], max(ady[i][k], ady[k][j]));
    		 }
		 }
	}
	}

int main() {
	int a,b,c;
	int caso =0;
	while(cin>>v>>e){
		caso++;
		for(int i = 0; i<v; i++){
			for(int j = 0; j<v; j++){
				ady[i][j] = inf ;
		}	
			ady[i][i] = 0 ;
		}
		if(v==0 && e ==0) break;
		while(e--){
			cin>>a>>b>>c;
			ady[a-1][b-1] = c;
			ady[b-1][a-1] = c;
		}
		floyd_warshall();
		for(int i =0; i<v; i++)ady[i][i] = 0;
		cin>>c;
		cout<<"Instancia "<<caso<<"\n";
		while(c--){
			cin>>a>>b;
			      cout<<ady[a-1][b-1]<<"\n";
		}
		cout<<endl;
	}
	return 0;

}