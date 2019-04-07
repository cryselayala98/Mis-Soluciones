#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

//https://vjudge.net/problem/UVA-10496

struct point{
	int y;
	int x;
};

int dist[14][14];
int memo[1<<14][14];
int v, target;

int dp(int mask, int idx){
	if(mask==target) return dist[idx][0]; 
	if( memo[mask][idx] != -1) return memo[mask][idx];
	int ans = INF; 
	for(int i=0; i<v; i++){
		if( !(mask & (1<<i))){ //pos no visitada
			ans = min(ans, dp(mask | (1<<i), i) + dist[idx][i]);
		}
	}
	return memo[mask][idx] = ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int sc; cin>>sc;
	int yini,xini, s; 
	while(sc--){
		vector<point>p;
		cin>>yini>>xini>>yini>>xini>>s;
		p.push_back(point{yini-1,xini-1});
		int a,b;
		v=s+1;
		while(s--){
			cin>>a>>b;
			p.push_back(point{a-1,b-1});
		}
		
		//definir dist

		for(int i =0; i<v-1; i++){
			for(int j =i+1; j<v; j++){
				dist[i][j]=dist[j][i]= abs(p[i].x - p[j].x)+ abs(p[i].y - p[j].y);
			}
		}
		target=(1<<v)-1;
		memset(memo, -1, sizeof(memo));
		cout<<"The shortest path has length "<<dp(0,0)<<endl;
	}
	return 0;
}