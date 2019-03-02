#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/136/A

int main() {
	int a; cin>>a;
	int friends[a];
	
	int b;
	for(int i =0; i<a; i++){
		cin>>b; 
		friends[b-1] = i+1;
	}
	for(int i =0; i<a; i++){
		if(i)cout<<" ";
		cout<<friends[i];
	}
	cout<<endl;
	
	return 0;
}