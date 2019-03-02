#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

//https://codeforces.com/contest/1095/problem/C

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

	int n; int k; cin>>n>>k;
	map<int, int>powers;
	
	int s = 0; 
	int n1 = n;
	
	int acum = 0;
	
	while(n1>0){
		int u= n1 & (-n1);
		acum+= u;
		n1-= u;
		powers[u*-1]++;
	}
	
	if(acum<k || powers.size() > k)cout<<"NO\n";
	else{
		cout<<"YES\n";
		int w = powers.size();
			for(auto x : powers){
				int mid = x.f/2;
				 while(powers[x.f]){
				 	if(w==k)break;
					powers[x.f]--;
					w++;
					powers[mid]+=2;
				}
		}
		bool es = 0; int suma = 0;
		for(auto x : powers){
			for(int i = 0; i< x.s; i++){
				if(es)cout<<" ";
				es = 1;
				cout<<x.f*-1;
			}
		}
		cout<<endl;
	}

	return 0;
}