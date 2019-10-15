#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/360/detalle/en

long long ncr(long long n, long long r) {
    if (r < 0 || n < r) return 0;
    r = min(r, n - r);
    long long ans = 1;
    for (int i = 1; i <= r; i++) {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	long long n,m; 
	
	while(cin>>n>>m, n+m){
		cout<<ncr(n,m)<<endl;
	}
	return 0;
}
