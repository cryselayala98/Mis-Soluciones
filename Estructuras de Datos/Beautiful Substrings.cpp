#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/101972/problem/H

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int c; cin>>c; int a,b,k; string aa,bb;
	while(c--){
		cin>>a>>b>>k>>aa>>bb; 
	int abc[26];
	set<char> aux_abc[26];
	memset(abc, 0, sizeof(abc));
	
	for(int i = k-1; i<a; i++){
		aux_abc[aa[i]-'a'].insert(aa[i-k+1]-'a');
	}
	long long res=0;
	for(int i =0; i<b; i++){
		abc[bb[i]-'a']++;
		for(auto j : aux_abc[bb[i]-'a']){
			res+= abc[j];
		}
	}
	
	cout<<res<<endl;
	}
	return 0;
}