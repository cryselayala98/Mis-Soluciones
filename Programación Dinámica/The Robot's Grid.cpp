#include <bits/stdc++.h>
using namespace std;

//http://trainingcenter.ufps.edu.co/clases/tarea/51/problema/57/258/en

unsigned long long grid[30][30];
unsigned long long val=0;

void dp_grid(int filas, int columnas){
	
	if(columnas==1 || filas==1){
		val++; return;
	}
	
	if(grid[filas][columnas]!=0){
		val+=grid[filas][columnas]; return;
	}
	columnas--;
	
	for(int i=1; i<=filas; i++){
		dp_grid(columnas, i);
	}
}

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	memset(grid, 0, sizeof(grid[0][0])*30*30);
	
	//precalculo
	for(int i=1; i<=25; i++){
		for(int j=1; j<=25; j++){
			dp_grid(i,j);
			grid[i][j]=val;
			val=0;
		}
	}
	
	int casos, a, b;
	cin>>casos;
	
	while(casos--){
		cin>>a>>b;
		cout<<grid[a][b]<<endl;
	}
	
	
	return 0;
}