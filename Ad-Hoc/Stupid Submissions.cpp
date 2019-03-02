#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/101972/problem/E

int main() {
	
	int c, n,m,k, b; char a;
	cin>>c;
	
	while(c--){
		cin>>n>>m>>k;
		char cases[n]; 
		for(int i =0; i<n; i++) cin>>cases[i];
		int res=0;
		while(m--){
			cin>>a;
			if(a=='A')k=n;
			else{
				cin>>b;
				if(b<=k){
				if(cases[b-1]=='S')	res++;
				}
				else k = b;
			}
 		} cout<<res<<endl;
	}
	return 0;
}