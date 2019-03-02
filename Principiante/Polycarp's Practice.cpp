#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define s second

//https://codeforces.com/contest/1006/problem/B

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n,k; cin>>n>>k;
	
	set<pair<int, int> > vals;
	
	int t;
	for(int i = 0; i<n; i++){
		cin>>t;
		vals.insert(mp(t*-1, i));
	}
	set<int> ind;
	int k1=k; int res = 0;
	for(auto z: vals){
		if(!k1) break;
		k1--;
		res+= z.f*-1;
		ind.insert(z.s);		
	}
	
	cout<<res;
	int i = 0; int ant=0 ;
	for(auto z : ind){
		z++;
		 if(i==k-1){
		cout<<" "<<(n-ant)<<endl;	
		}
		else if(i==0)cout<<" "<<z;
		else cout<<" "<<(z-ant);
		
		ant = z;
		i++;
	}
	
	
	return 0;
}