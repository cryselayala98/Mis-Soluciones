#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/102063/problem/B

int mcd (int a, int b) {
	while (b != 0){
		a %= b;
		swap(a, b);
	}
	return a;
}

int mcm (int a, int b) {
	return a * b / mcd(a, b);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int a,b; cin>>a>>b;
	cout<<mcm(a,b)<<endl;
	return 0;
}