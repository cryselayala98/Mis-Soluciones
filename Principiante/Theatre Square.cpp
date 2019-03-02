#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/236459/problem/B

int main() {
	int n,m,a; cin>>n>>m>>a;
	int nn = ceil((double)n/a);
	int mm = ceil((double)m/a);
	cout<<(long long)nn*mm<<endl;
	return 0;
}