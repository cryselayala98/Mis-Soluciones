#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000

//http://trainingcenter.ufps.edu.co/problemas/58/detalle/en

int X,Y, TIME_MAX, p; //p->amount of prizes

int dy[] = {0,1,0,-1, 0};
int dx[] = {0,0,1, 0,-1}; 

int prizes[21][21][1005];   //rows,cols,times
int memo[21][21][1005]; //maximum amount of dollars that he won int a time

int dp(int x, int y, int second){ 
		
	if (y < 0 || y >= Y || x < 0 || x >= X){

		return -inf;
	} 
	if(second>TIME_MAX)return 0;
	if(memo[x][y][second]!=-1) return memo[x][y][second];
	
	
	
	int maxi_dollars =0;
	for(int i = 0; i<5; i++){
		int p = dp(x + dx[i], y + dy[i], second+1)+prizes[x][y][second];
		
		maxi_dollars=max(maxi_dollars, p);
	}

	return memo[x][y][second] = maxi_dollars;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; 
	cin>>t;
	
	while(t--){
		memset(prizes, 0, sizeof(prizes));
		memset(memo, -1, sizeof(memo));
		int p; TIME_MAX = 0;
		cin>>X>>Y>>p;
		int xs,ys; 
		cin>>xs>>ys; xs--; ys--; 
		int a,b,c,d;
		int p1=p;
		while(p1--){
			cin>>a>>b>>c>>d;
			prizes[a-1][b-1][c] = d;
			TIME_MAX = max(TIME_MAX, c);
		}
		cout<<dp(xs,ys,0)<<endl;
	}
	return 0;
}