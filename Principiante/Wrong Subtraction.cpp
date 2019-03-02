#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/977/A
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n,k; cin>>n>>k;
	while(k--){
		int aux = n%10;
		if(aux!=0) n--;
		else n= n/10;
	}
	cout<<n<<endl;
	return 0;
}