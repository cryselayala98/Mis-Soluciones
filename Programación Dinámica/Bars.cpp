#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

//https://vjudge.net/problem/UVA-12455

int vars[25];
int value[1005]; 
int n;
int obj;

int search(int idx, int x){
	if(x==0)return 1;	
	if(x<0|| idx>=n)return 0;
	if(value[x]!=-1) return value[x];
	value[x]= max(search(idx+1, x), search(idx+1, x-vars[idx]));
	return value[x];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin>>t;
	
	while(t--){
		cin>>obj; cin>>n;
		for(int i =0; i<n; i++)cin>>vars[i];

		memset(value, -1, sizeof(value));
	    int best=search(0,obj);

		if(!best)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	
	return 0;
}

