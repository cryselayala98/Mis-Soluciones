#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1104/problem/D

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int i, low,high;
	
	string a; cin>>a; char b;
	
	while(a!="end" && a!="mistake"){
		i = 1; low =0; high = 1;
		while(1){
			
			cout<<"? "<<low<<" "<<high<<endl;  fflush(stdout);
			cin>>b;
			
			if(b=='x'){
				while(low<high){
					int mid = (low+high)>>1;
					if(low == mid) break;
					
					cout<<"? "<<low<<" "<<mid<<endl;  fflush(stdout);
					cin>>b;
					
					if(b=='x') high = mid;
					else low = mid;
					
				}
				cout<<"! "<<high<<endl;  fflush(stdout); break;
				
			}else{
				low = high;
				high = low<<1;
				
			}
		}
		cin>>a;
	}
	return 0;
}