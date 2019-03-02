#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1095/problem/B

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n; cin>>n;
	
	int arr[n];
	for(int i = 0; i<n; i++)cin>>arr[i];
	if(n<3)cout<<0<<endl;
	else{
	sort(arr, arr+n);
	cout<<min(arr[n-1]-arr[1], arr[n-2]-arr[0])<<endl;
	}
	return 0;
}