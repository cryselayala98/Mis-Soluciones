#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-13106

int grid[305][305];
int memo[305][305];
int y,x;

int dp(int mov, int idx, int c){
	if(c==0){ //moverme por la sig col
		if(idx>=x) return 0;
		if(memo[mov][idx]!=-1)return memo[mov][idx];
		return memo[mov][idx]= max(dp(mov, idx+1,c), dp(mov, idx+2,c)+grid[mov][idx]);
	}else{   //moverme por la sig fila
		if(idx>=y) return 0;
		if(memo[idx][mov]!=-1)return memo[idx][mov];
		return memo[idx][mov]= max(dp(mov, idx+1,c), dp(mov, idx+2,c)+grid[idx][mov]);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	while(cin>>y>>x){
		for(int i =0; i<y; i++){
			for(int j=0; j<x; j++){
				cin>>grid[j][i];
			}
		}
		memset(memo, -1, sizeof(memo));
		swap(y,x);
		for(int i=0; i<y; i++){
			grid[i][0]=dp(i, 0,0); /*max col*/
		}
		memset(memo, -1, sizeof(memo));
		cout<<dp(0,0,1)<<endl;
	}
	return 0;
}