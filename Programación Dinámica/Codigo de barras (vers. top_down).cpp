#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000

//http://trainingcenter.ufps.edu.co/clases/tarea/51/problema/61/257/es

long long memo[55][55][55];
int N,K,M;

long long dp(int n, int k, int m){

	if(n>N || k>K) return 0;
	if(n==N && k==K){

		return 1; //se forma 1 conjunto	
	} 
	if(memo[n][k][m]!=-1) return memo[n][k][m];

		long long suma = 0;
	for(int i =1; i<=M; i++){

	suma+=	dp(n+i, k+1, m);
	}

	memo[n][k][m] = suma;
		
		return 	memo[n][k][m];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	while(cin>>N>>K>>M){
		memset(memo, -1, sizeof(memo));
		cout<<dp(0,0,0)<<endl;
	}
	return 0;
}