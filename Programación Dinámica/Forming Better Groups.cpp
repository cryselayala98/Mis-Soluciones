#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-13294

int c[22];
long long memo[1<<21];
int n,d, target;

long long dp(int mask){
	
	if(mask==target)return 1;	
	if(memo[mask]!=-1)return memo[mask];
	
	int i,j,k;
	long long ans=0;
	for(i =0; i<n; i++) if(!(mask & (1<<i))) break; //tomar el primer bit no encendido
	for(j=i+1; j<n; j++){
		if((mask & (1<<j))) continue; //verificar bit no encendido
		for(k=j+1; k<n; k++){
			if((mask & (1<<k)))continue;  //verificar bit no encendido
			if(max(c[i], max(c[j], c[k])) - min(c[i], min(c[j], c[k])) <=d)
				ans += dp(mask | (1<<i) | (1<<j) | (1<<k)); //prender ese conjunto de bits
		}
	}
	return memo[mask]=ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	while(cin>>n>>d, n){
		for(int i =0; i<n; i++)cin>>c[i];
		memset(memo, -1, sizeof(memo));
		target=(1<<n)-1;
		cout<<(dp(0))<<endl;
	}
	return 0;
}