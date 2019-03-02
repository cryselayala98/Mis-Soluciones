#include <bits/stdc++.h>
using namespace std;

int main() {
	int casos;
	cin>>casos;
	while(casos--){
		int d, e; cin>>d>>e;
		int tabla[d][e];
		
		
		for(int i=d-1; i>=0; i--){
		for(int j=e-1; j>=0; j--){
			cin>>tabla[i][j];
		}	
		}
		
		for(int i=0; i<d; i++){
			bool ii=false;
			for(int  j =0; j<e; j++){
				if(ii){
					cout<<" ";
				}ii=true;
				cout<<tabla[i][j];
				
			}cout<<endl;
		}
	
	}
	return 0;
}