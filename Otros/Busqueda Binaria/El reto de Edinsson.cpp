#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/286/detalle/es

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n, q; cin>>n>>q;
	
	vector<int> lista;
	
	int a;
	for(int i = 0; i<n; i++){
		cin>>a;
		lista.push_back(a);
	}
	sort(lista.begin(), lista.end());
	
	while(q--){
		cin>>a;
		bool es = 0;
		if(binary_search(lista.begin(), lista.end(), a)){
			for(int i = 0; i<n-1; i++){
				for(int j= i+1; j<n; j++){
					int b= a - (lista[i]+lista[j]);
					if(b!= lista[i]&& b!=lista[j] && binary_search(lista.begin(), lista.end(), b)){
						cout<<lista[i]<<" "<<lista[j]<<" "<<b<<endl;
						es = 1;
						goto final;
					}
				}
			}
		}
		final:
		if(!es)cout<<"NO"<<endl;
	}
	return 0;
}
