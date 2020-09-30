#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
const int MAX=100001;
int dp[MAX+1];
int art[MAX+1];
int k;
int f(int t){
	if(t<0) return INF;
	if(dp[t]!=-1) return dp[t];
	dp[t]=t;
	//int ans=INF;
	for(int i=0;i<k;i++){
	dp[t]=min(dp[t],f(t-art[i]));
	}
	return dp[t];
}
int main() {
	int n;
	while(cin>>n>>k){
		for(int i=0;i<k;i++){
			cin>>art[i];
		}
		cout<<f(n)<<endl;
		memset(dp,-1,sizeof(dp));
	}
}
