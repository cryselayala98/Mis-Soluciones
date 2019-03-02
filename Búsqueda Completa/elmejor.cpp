#include <bits/stdc++.h>
using namespace std;
int n;
void recursivo(string numeros [], int tam, string tal, int ini){
	
	if(tam==5){
		
		cout<<tal<<endl;
		return;
	}
	if(tam>0){
	tal+=" ";	
	}
	tam++;
	
	for(int i=ini; i<n; i++){
	

		recursivo(numeros, tam, tal+numeros[i], i+1 );
	
	}

}
int main() {
	int cases;
	cin>>cases;

	while(cases--){
		cin>>n;
		
		string numeros [n];
		int t1=n;
		int i=0;
		while(t1--){
		cin>>numeros[i];
		i++;
		}
		if(n==5){
			bool t=false;
			for(int j=0; j<5; j++){
				if(t){
					cout<<" ";
				} t=true;
				cout<<numeros[j];
			}
			cout<<endl;
		}else{
			recursivo(numeros, 0, "",0);
		}
		if(cases!=0){
		cout<<endl;	
		}
	}
	return 0;
}