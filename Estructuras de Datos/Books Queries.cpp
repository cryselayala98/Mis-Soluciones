#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

//https://codeforces.com/contest/1066/problem/C

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int q; cin>>q;
	
	int books = 0;
	map <int, int> ord_left, ord_right, u; int l1= 0,r1=0;
	char c; int idx;
	
	while(q--){
		
		cin>>c>>idx;
		if(c=='L'){
			
			int b = ord_left.size()+1;
			books++;
			ord_left[idx] = b; r1++;
			u[idx] = 0;
		
			
		}else if(c=='R'){
			
			int b = ord_right.size()+1;
			books++;
			ord_right[idx] = b; l1++;
			u[idx] = 1;
		
			
		}else if(c=='?'){
			
			int i = 0;
			if(!u[idx]){
				i = ord_left.size() - ord_left[idx];
			}else{
		
				i = ord_right.size() - ord_right[idx];
			}
		
			i = min(i, (books-i-1));
			cout<<i<<endl;
		}
	}
	
	
	return 0;
}