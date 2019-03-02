#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1015/problem/A

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n,m; cin>>n>>m;
	set<int>points;
	int l,r;
	for(int i = 0; i<n; i++){
		cin>>l>>r;
		for(int j =l-1; j<=r-1; j++) points.insert(j);
	}
	cout<<m-points.size()<<endl;
	bool es = 0;
	for(int i = 0; i<m; i++){
		if(!points.count(i)){
			if(es)cout<<" ";
			es = 1;
			
			cout<<i+1;
		}
	}cout<<endl;
	
	return 0;
}