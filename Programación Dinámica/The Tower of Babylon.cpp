#include <bits/stdc++.h>
using namespace std;
#define bloque pair<long long, pair<long long, long long> >
#define f first
#define s second
#define ag(a,b,c) blo.insert(make_pair(a, make_pair(b,c)));

//https://vjudge.net/problem/UVA-437

int n;
set<bloque> blo; vector<bloque> bloques;
long long memo[200];

long long dp(int idx){
	
	if(memo[idx]!=-1) return memo[idx];
	
	long long ans= 0;
	
	long long x = bloques[idx].f, y = bloques[idx].s.f;
	for(int i = 0; i<n; i++){
		long long x1 = bloques[i].f, y1 = bloques[i].s.f;
		if(x1<x && y1<y){
			ans = max(ans, dp(i)+bloques[i].s.s);
		}
	}
	
	return memo[idx] = ans;
	
}

int main() {
	
	long long x,y,z; int i = 1;
	while(cin>>n,n){
		blo.clear(); bloques.clear();
		cout<<"Case "<<i<<": maximum height = ";
		i++;
		while(n--){
		cin>>x>>y>>z;
		ag(x,y,z);
		ag(y,x,z);
		ag(y,z,x);
		ag(z,y,x);
		ag(x,z,y);
		ag(z,x,y);
		}
		
		for(auto x: blo) bloques.push_back(x);
		n = bloques.size();
		memset(memo, -1, sizeof(memo));
		
		long long maxi = 0;
		for(int i = 0; i<n; i++) maxi = max(maxi, dp(i)+bloques[i].s.s);
		
		cout<<maxi<<endl;
	}
	
	return 0;
}