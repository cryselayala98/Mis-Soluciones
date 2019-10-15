#include <bits/stdc++.h>
using namespace std;
#define punto pair<double, double>
#define f first
#define s second

//http://trainingcenter.ufps.edu.co/problemas/281/detalle/es

double pendiente(double x1, double y1, double x2, double y2){
	return(y2-y1) / (x2-x1);
}

int cuadrante (int x, int y){
	if(x>=0 && y>=0) return 1;
	if(x<0 && y>=0) return 2;
	if(x<0 && y<0) return 3;
	return 4;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	vector<punto> puntos;
	double n,k, x,y;
	
	while(cin>>n>>k){
		for(int i = 0; i<n; i++){
			cin>>x>>y;
			puntos.push_back(make_pair(x,y));
		}
		
		while(!puntos.empty()){
			punto actual = puntos[0];
			puntos.erase(puntos.begin());
			for(int i = 0; i<puntos.size(); i++){
				punto sig = puntos[i];
				
				if((cuadrante(actual.f,actual.s) == cuadrante(sig.f, sig.s)) &&  pendiente(0,0,actual.f, actual.s)== pendiente(0,0, sig.f, sig.s)){
					puntos.erase(puntos.begin() + i);
					i--;
				}
			}
			k--;
		}
		
		if(k>= 0)cout<<"ATACAR"<<endl;
		else cout<<"ESPERAR"<<endl;
	}
	
	return 0;
}