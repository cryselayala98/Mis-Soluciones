#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/102007

long long p(long long a, long long b, long long c){
	return 2*(a*b + a*c + b*c);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n; cin>>n;
	long long minip = 10000000000;
	for(int i = 1; i<=sqrt(n); i++){
		for(int j = i; j<=sqrt(n); j++){
			long long a = i, b= j;
			long long c = n / (a*b);
			if(a*b*c==n){
				minip = min(minip, p(a,b,c));	
			}
		}
	}
	cout<<minip<<endl;
	
	return 0;
}
