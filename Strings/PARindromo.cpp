#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/385/detalle/es

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	string a;
	while(getline(cin,a)){
		string b = "";
		for(auto x:a)if(x!=' ')b+=x;
		b+="+-*"; 
		bool par =0, impar=0;
		
		//cadenas pares
		for(int i = 0; i< b.size()-2; i++){
			if(b[i]==b[i+1]){ par=1; break;}
		}
		
		for(int i = 0; i< b.size()-3; i++){
			if(b[i]==b[i+2]){ impar=1; break;}
		}
		
		if(par && impar)cout<<"Ambos"<<endl;
		else if(par)cout<<"Par"<<endl;
		else if(impar)cout<<"Impar"<<endl;
		else cout<<"Ninguno"<<endl;
	}
	
	return 0;
}
