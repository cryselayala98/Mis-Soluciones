#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1003/problem/B

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int a,b,x; cin>>a>>b>>x;
	
	//max = a
	bool s = 0;
	if(b > a) s = 1;
	
		while(x>1){
			cout<<s;
			if(!s)a--;
			else b--;
			s= s==0?1:0;
			x--;
		}
		
		if(!s){
			 while(a--)cout<<0;
			 while(b--)cout<<1;
		}else{
			 while(b--)cout<<1;
			 while(a--)cout<<0;
		}
		
		cout<<endl;
	
	
	return 0;
}