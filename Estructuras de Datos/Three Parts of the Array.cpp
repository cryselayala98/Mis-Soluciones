#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

//https://codeforces.com/contest/1006/problem/C

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n; cin>>n;
	long long arr[n];
	map<long long, int>arr2,arr3;
	long long acum = 0;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
		acum+= arr[i];
		arr2[acum] = i+1;
	}
	acum=0;
	
	for(int i = n-1; i>=0; i--){
		acum+= arr[i];
		arr3[acum] = i+1;
	}
	
	acum = 0;
	
	for(auto x : arr2){
		
		if(arr3[x.f] && x.s<arr3[x.f]){
			acum= x.f;
		}
		
	}
	
	cout<<acum<<endl;
	
	return 0;
}