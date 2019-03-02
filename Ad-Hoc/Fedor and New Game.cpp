#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/contest/279190?fbclid=IwAR1prf92xWiF4gOb-xyx9-QtT8jfhf_ZtAIH48cXFNu3mFJyL68hDvyuPQg#problem/B

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n,m,k; cin>>n>>m>>k;
	vector<int > soldados;
	m++;
	while(m--){
		int a; cin>>a;
		soldados.push_back(a);
	}
	int amigos=0;
	for(int i = 0; i<soldados.size()-1; i++){
		int aux = soldados[soldados.size()-1] ^ soldados[i];
		bitset<32> s(aux);
		if(s.count()<=k)amigos++;
	}
	cout<<amigos<<endl;
	return 0;
}