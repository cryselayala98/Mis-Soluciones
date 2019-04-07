#include <bits/stdc++.h>
using namespace std;
#define m 998244353

//https://codeforces.com/gym/101982

vector<int> vals;  //existencia de cada ejercicio con nivel de dificultad
long long memo[1005][1005]; //indice actual, numero de elementos usados

int n,k;

long long dp(int idx, int cont){

	if(cont==k) return 1;	
	if(memo[idx][cont] != -1) return memo[idx][cont];	
	long long ans = 0;
	for(int i = idx; i<n; i++ ) ans = ((ans%m) + ((dp(i+1, cont+1)%m)*(vals[i]%m) % m)) % m;
	return memo[idx][cont] = ans ;
	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	cin>>n>>k;
	map<int, int>c;
	int y;
	int n1=n;
	while(n1--){
		cin>>y; 
		c[y]++;
	}
	for(auto x:c){
		vals.push_back(x.second);
	}
	n=vals.size();
	memset(memo, -1, sizeof(memo));
	cout<<dp(0, 0)<<endl;
	
	return 0;
}