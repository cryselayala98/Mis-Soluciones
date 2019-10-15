#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVALive-5814

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin>>t;
	int a,b,c;
	int i = 1;
	while(t--){
		cin>>a>>b>>c;
		cout<<"Case "<<i<<": ";
		if(a<=20 && b<=20 && c<=20)cout<<"good"<<endl;
		else cout<<"bad"<<endl;
		i++;
	}
	return 0;
}
