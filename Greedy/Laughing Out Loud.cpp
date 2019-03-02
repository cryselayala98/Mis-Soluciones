#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/100589/problem/I

long long r [100005];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int t; string a;
	cin>>t;
	while(t--){
		cin>>a;
		int n = a.size(); 
		r[0] = (a[0]=='L'); 
		for(int i = 1; i<n; i++){
			r[i] = r[i-1]; 
			if(a[i]=='L'){
				r[i]++;  
			}
		}
	
		
		long long res = 0;
		
		for(int i = 1; i<n-1; i++){
			if(a[i]=='O'){
				res+= (r[i]*(r[n-1]-r[i]));
			}
		}
		
		cout<<res<<endl;
		
	}
	
	return 0;
}