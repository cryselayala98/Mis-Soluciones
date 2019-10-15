#include <bits/stdc++.h>
using namespace std;

//bitmask, busqueda completa
//https://codeforces.com/contest/868/problem/C

int eqs[1<<4]; //verifica si exite alguna combinacion de conocimiento de problemas para cada equipo

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n,k; cin>>n>>k;
	 int n1=n;
	while(n--){
		int a = 0;
		for(int i = 0; i<k; i++){
			int r; cin>>r; a+=r<<i;
		}
		eqs[a]++;
	}
	bool es = 0;
	for(int i = 0; i<(1<<k); i++){
		for(int j = 0; j<(1<<k); j++){
			if(!(i&j) && eqs[i] && eqs[j]){ // ejercicios que maximo 1 de los equipos debe conocer ej 1001 & 0110.
				es = 1; 
				goto final;
			}
		}	
	}
	
	
	final:
	if(es)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	return 0;
}