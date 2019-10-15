#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/contest/300253#problem


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n;
	cin>>n;
	long long vals[n];
	
	for(int i = 0; i<n; i++)cin>>vals[i];
	string a; cin>>a;
	
	string b = a; reverse(b.begin(), b.end());
	
	long long maxi = 0;
	for(int i = 0; i<n; i++)if(a[i]=='B')maxi+=vals[i];
	
	long long normal= maxi, invertido = maxi;

	for(int i = 0; i<n; i++){
		
		if(a[i]=='B')normal-=vals[i];
		else if(a[i]=='A')normal +=vals[i];
		
		if(b[i]=='B')invertido-=vals[n-(i+1)];
		else if(b[i]=='A')invertido +=vals[n-(i+1)];
		
		maxi = max(maxi, max(normal, invertido));
	}
	
	cout<<maxi<<endl;
	return 0;
}