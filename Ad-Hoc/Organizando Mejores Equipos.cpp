#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

//https://trainingcenter.cloud.ufps.edu.co/problemas/285/detalle/es

int main() {
int casos, grupos, integrantes,a,b,cc;
string nombre;
cin>>casos;
int c=0;
while(casos--){
	c++;
	cout<<"Caso "<<c<<":"<<endl;
	cin>>grupos;
	vector<pair<int, string> >puntaje;
	set<string> eliminados;
	while(grupos--){
		cin>>integrantes;
		while(integrantes--){
			cin>>nombre>>a>>b>>cc;
			puntaje.pb(mp((a+b+cc)*-1, nombre));
		}
	}
		sort(puntaje.begin(), puntaje.end());
		int r =0;
		for(int i=0; i<puntaje.size(); i++){
			if(i%3==0){
				r++;
				cout<<"Equipo "<<r<<":"<<endl;
			}
			cout<<puntaje[i].second<<endl;
		}
}


	return 0;
}
