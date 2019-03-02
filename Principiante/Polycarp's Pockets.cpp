#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1003/problem/A

int coins[101];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n; cin>>n; int a;
	
	while(n--){
		cin>>a;
		coins[a-1]++;
		
	}
	int maxi =0; int r;
	for(int i =0; i<100; i++) if(coins[i]>maxi) maxi = coins[i], r = i+1;
	
	cout<<maxi<<endl;
	
	
	return 0;
}