#include <bits/stdc++.h>
using namespace std;

/*https://u...content-available-to-author-only...e.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=565*/

int n, val, arr[20];
vector<int> rta;

int maxx ; 

void back(int acum, int ini, vector <int> aux){
	acum += arr[ini];
	aux.push_back(arr[ini]);
	if(acum>maxx || (acum==maxx && aux.size() > rta.size())){
		maxx = acum;
		rta = aux;
	}
	for(int i = ini+1; i<n; i++){
		if(acum+arr[i]<=val) back(acum, i, aux);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	while(cin>>val>>n){
		rta.clear();
		int acum = 0;
		for(int i = 0; i<n; i++){
			cin>>arr[i];
		}
		maxx = 0;
		vector <int>aux;
		for(int i = 0; i< n; i++){
					back(0, i, aux);
				}
		for(int i = 0; i<rta.size(); i++){
				cout<<rta[i]<<" ";
		}cout<<"sum:"<<maxx<<"\n";

	}
	return 0;
}