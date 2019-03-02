#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1006/problem/A

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int n; cin>>n;
	int a[n]; 
	for(int i =0; i<n; i++){
		cin>>a[i];
	}
	int z = 1;
	while(z<=10){
			for(int i =0; i<n; i++){
				if(a[i]%10==z) a[i]=(z%2==0 ? a[i]-1:a[i]+1);
				else if(a[i]%10==0)a[i]--;
			}
			z++;
	}
	for(int i =0; i<n; i++){
		if(i)cout<<" ";
		cout<<a[i];
	}cout<<endl;
	
	
	return 0;
}