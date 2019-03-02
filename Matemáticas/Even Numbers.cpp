#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/101972/problem/J

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int c; cin>>c;
	while(c--){
		long long n; cin>>n;
		long long n1=1; long long naux=n;
		//number of odd numbers for n = (2** (bits 1 in n))
		while(naux>0){
			n1*=2; naux-= naux&-naux;
		}
		cout<<(n+1)-n1<<endl;
	
	}
	return 0;
}