#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mi -20000000000
#define ma  20000000000

//https://codeforces.com/gym/100589/problem/J

vector<long long>a,b,c;
long long p,q,r,v;
long long acum[100030]; //Guarda acum de la cantidad de upper de c[] para cada b[i] 

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin>>t;
	
	while(t--){
		a.clear(); b.clear(); c.clear();
		a.pb(mi); b.pb(mi); c.pb(mi);
		
		cin>>p ; 
		for(int i = 0; i<p; i++){
			cin>>v;   a.pb(v);
		}
		
		cin>>q ; 
		for(int i = 0; i<q; i++){
			cin>>v;  b.pb(v);
		}
		
		cin>>r ; 
		for(int i = 0; i<r; i++){
			cin>>v;  c.pb(v);
		}
	    b.pb(ma);
		while(c.size()<b.size()) c.pb(ma);
		
		for(int i= b.size()-2; i>=1; i--){
		
			acum[i]= 0L;
			if(i<b.size()-2) acum[i] += acum[i+1];
			
			vector<long long>::iterator aux =  upper_bound(c.begin() + i, c.end(), b[i]);
			long long pos = (aux - c.begin()); 
			if(c[pos-1]==b[i]) pos--;
			
		
			if(c[pos]<ma)acum[i] +=(long long) (r - (pos-1));
		}
		
		long long res = 0;
		
		
		while(b.size()<a.size())b.pb(ma);
		
		for(int i= a.size()-1; i>=1; i--){
			
			vector<long long>::iterator aux =  upper_bound(b.begin() + i, b.end(), a[i]);
			int pos = (aux - b.begin()); 
			if(b[pos-1]==a[i]) pos--;
			if(b[pos]<ma) res+= acum[pos];
		}
		cout<<res<<endl;
	}
	
	return 0;
}