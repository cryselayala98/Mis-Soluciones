#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-11831

int main() {
	int filas, col, n;
	
	cin>>filas>>col>>n;
	while(filas!=0 && col!=0 && n!=0){
	int cont=0;
	char matriz[filas][col];
	
	int x=0; int y=0; //pos ini
	char orientacion;
	for(int i=0; i<filas; i++){
		for(int j =0; j<col; j++){
			cin>>matriz[i][j];
			
			if(matriz[i][j]=='N' || matriz[i][j]=='L' || matriz[i][j]=='S' || matriz[i][j]=='O'){
				orientacion= matriz[i][j];
				x=i; y=j;
			}
		}
	}
	
	string t; cin>>t; 
	for(int i=0;i<n; i++){
	//cout<<x<<y<<endl;	
		char r=t[i];
		
		if(r=='E'){
			
			if(orientacion=='N'){
				orientacion='O';
			}else if(orientacion=='O'){
				orientacion='S';
			}else if(orientacion=='S'){
				orientacion='L';
			}else{
				orientacion='N';
			}
			
		}else if(r=='D'){
			if(orientacion=='N'){
				orientacion='L';
			}else if(orientacion=='O'){
				orientacion='N';
			}else if(orientacion=='S'){
				orientacion='O';
			}else{
				orientacion='S';
			}
		}else{
		//	cout<<"al frente "<<endl;
			if(orientacion=='N'){
				
			if(x-1 >= 0 ){
			if(matriz[x-1][y]!='#')	x--;
			
			}	
				
			}else if(orientacion=='O'){
			
			if(y-1 >= 0){
			if(matriz[x][y-1]!='#')	y--;
			
			}
			
			}else if(orientacion=='S'){
			
			if(x+1 < filas){
				if(matriz[x+1][y]!='#')x++;
			
			}
			
				
			}else{//"L"
			
				if(y+1 < col){
			if(matriz[x][y+1]!='#')	y++;
			}
			}
			
				if(matriz[x][y]=='*'){
					cont++;
					matriz[x][y]='.';
				
				}
			
		}
		
	}

	
		cout<<cont<<endl;
	cin>>filas>>col>>n;
	}
	return 0;
}
               