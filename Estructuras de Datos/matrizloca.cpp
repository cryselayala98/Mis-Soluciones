#include <bits/stdc++.h>
using namespace std;

int main() {
	int casos;
	cin>>casos;
	while(casos--){
		int a, b;
		cin>>a>>b;
		int matriz[a][b];
		for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
		cin>>	matriz[i][j];
		
		//regla 1
		if(i==0 || i%2==0){
			matriz[i][j]++;
		}
		//regla 2
		if(j==0 || j%2==0){
			matriz[i][j]+=2;
		}
		//regla 3
		if(i%2==1 && j%2==1){
			matriz[i][j]-=3;
		}
		}	
		}
		
			for(int i=0; i<a; i++){
				bool r=false;
		for(int j=0; j<b; j++){
			if(r){
				cout<<" ";
			}r=true;
	cout<<	matriz[i][j];
		}
		cout<<endl;
	}
	
	}
	
	return 0;
}