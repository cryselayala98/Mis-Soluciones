
#include <bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1167
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int casos;
	string cc;
		string arbol;	
	  getline(cin, cc);
	  casos=atoi( cc.c_str() );
 
	getline(cin, arbol);
	while(casos-->0){
 
		double cont=0.0;
		map <string, double> porcentaje;
 
 
		while(getline(cin, arbol)){
  
			if(arbol.size()==0){
				break;
		}
 
		if(porcentaje.count(arbol)){
			porcentaje [arbol]=	porcentaje [arbol]+1.0;
		}else{
				porcentaje [arbol]=1.0;
 
		}
	cont++;
	} 
	double porc= 100.0/cont;
	for(map<string, double> :: iterator it=porcentaje.begin(); it!=porcentaje.end(); it++){
		double v= it->second * porc;
 
		cout  <<it ->first<<" ";
		cout <<   fixed << setprecision(4) << v << "\n";
	}
	if(casos>0){cout<<"\n";}
	}
	return 0;
}