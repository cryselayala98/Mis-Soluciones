#include <bits/stdc++.h>
using namespace std;
#define f first
#define s secong
#define pb push_back
#define mp make_pair

//https://codeforces.com/problemset/problem/996/A

typedef long long ll;
typedef pair <int, int> p;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

    int n; cin>>n;
	int billetes [] = {100,20,10,5,1};
	int res = 0; int div;
	
	for(int i = 0; i < 5 && n>0; i++){
		div = n / billetes[i];
		n-= div*billetes[i];
		res+=div;
	}
	cout<<res<<"\n";

    return 0;
}


