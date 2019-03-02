#include <bits/stdc++.h>
using namespace std;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1121*/

	int main() {
	int n,m,s;
	string a;
	while(cin>>n>>m>>s, n){
		char grid[n][m];
		int n1=n;
		int i=0;
		int ai=0; int aj=0;
		char actual = 'N';
		while(n1--){
			cin>>a;
			for(int j=0; j<m; j++){ 
				grid[i][j] = a[j];
				if(a[j]== 'N' || a[j]== 'S' || a[j]== 'L' || a[j]== 'O') ai= i, aj=j, actual = a[j];
			}
			i++;
		}
		//leer coordenadas
		cin>>a;
		int cont=0;
		for(int k=0; k<s;k++){
			char b= a[k];
		//	cout<<k<<" "<<a[k]<<endl;
			if(b=='F'){
				int bi=ai; int bj=aj;
			switch(actual){
				case 'N': bi-=1;
				break;
				case 'S': bi+=1;
				break;
				case 'L':  bj+=1;
				break;
				default:  bj-=1; //O
			}
			if(bi>=0 && bj>=0 && bi<n && bj<m && grid[bi][bj]!='#'){ 
				if(grid[bi][bj]=='*') cont++;
				grid[bi][bj]='.';
				ai=bi;
				aj=bj;
			}
			}else if(b=='D'){
				switch(actual){
				case 'N': actual='L';
				break;
				case 'S': actual='O';
				break;
				case 'L':  actual='S';
				break;
				default: actual= 'N';  //O	
				}
				
			}else{ //b=='E'
				switch(actual){
				case 'N': actual='O';
				break;
				case 'S': actual='L';
				break;
				case 'L':  actual='N';
				break;
				default: actual= 'S';  //O	
				}
			}
		
		}
		cout<<cont<<"\n";
	}
		return 0;
	}