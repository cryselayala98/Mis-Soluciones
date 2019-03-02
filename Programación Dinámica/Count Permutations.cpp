#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/100589/problem/G

long long memo[1<<16][16];
int n,k;

long long dp(long long mask, int previous){ //mask almacena los bits que ya hayan sido tomados (bits 0)
	if(!mask)return 1; //todos los digitos se han usado, una nueva permutación
	
	if(memo[mask][previous]!=-1) return memo[mask][previous];
	
	memo[mask][previous] = 0;
	for(int i = 1; i<=n; i++){
		if((mask & (1<<(i-1)) ) && (!previous || abs(previous - i)<=k)){
			memo[mask][previous]+= dp(mask ^ (1<<(i-1)), i);
		}
	}
	
	
	return memo[mask][previous];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin>>t;
	
	
	while(t--){
		cin>>n>>k;
		memset(memo, -1, sizeof(memo));
		cout<<dp((1<<n)-1, 0)<<endl;
	}
	
	return 0;
}