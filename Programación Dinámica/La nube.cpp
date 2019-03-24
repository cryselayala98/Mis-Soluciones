#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000

//http://trainingcenter.ufps.edu.co/problemas/59/detalle/es

int canciones_albumes[35], memoria_canciones[35];
int memo[35][5125];
int n;

int dp(int idx, int k){
	//cout<<idx<<" "<<k<<endl;
	if(k<0) return -inf;
	if(idx>=n) return 0;
	
	if(memo[idx][k]!=-1) return memo[idx][k];
	
	memo[idx][k] = max(dp(idx+1, k), dp(idx+1, k-memoria_canciones[idx]) + canciones_albumes[idx]);
//	cout<<memo[idx][k] <<" "<<k<<endl;
	return memo[idx][k];
}

int main() {
	ios::sync_with_stdio(0);cin.tie(NULL);
	
	int t,k; cin>>t;
	while(t--){
		cin>>n>>k;
		k*=1024;
		memset(memo, -1, sizeof(memo));
		
		for(int i = 0; i< n; i++){
			cin>>canciones_albumes[i];
		}
		
		for(int i = 0; i< n; i++){
			cin>>memoria_canciones[i];
		}
		
		cout<<dp(0, k)<<endl;
	}
	
	return 0;
}