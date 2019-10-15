#include <bits/stdc++.h>
using namespace std;

//https://juezguapa.com/concursos/concurso-interno-de-programacion-3/problemas/enunciado/g-no-compila

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n,m; string w; bool es =0;
	while(cin>>n>>m){
		if (es)cout<<" "<<endl;
		es=1;
		cout<<"spint mat["<<n<<"]["<<m<<"] = ";
		cout<<"{ ";
		for(int i = 0; i<n; i++){
			if(i)cout<<",";
			cout<<"{";
			for(int j =0; j<m; j++){
				cin>>w;
				if(j)cout<<",";
				cout<<w;
			}
			cout<<"}";
			
		}
		cout<<" };";
	}
	cout<<endl;
	return 0;
}
