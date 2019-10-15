#include <bits/stdc++.h>
using namespace std;
long long x, y;

//https://trainingcenter.cloud.ufps.edu.co/problemas/378/detalle/en

long long extendedEuclid(long long a, long long b) {
    if(b == 0) { x = 1; y = 0; return a; }
    long long d = extendedEuclid(b, a % b);
    long long temp = x;
    x = y;
    y = temp - (a/b)*y;
    return d;
}

int modInverse(long long a, long long mod) {
    int d = extendedEuclid(a, mod);
    if (d > 1) return -1;
    return (x % mod + mod) % mod;
}

long long ncr(long long n, long long r, long long mod) {
    if (r < 0 || n < r) return 0;
    long long h = (n%mod - r%mod + mod)%mod;
    r = min(r, h);
    long long ans = 1L;
    for (long long i = 1L; i <= r; i++) {
    	long long a = ((n%mod)-(i%mod)+mod +(1%mod))%mod;
    	long long divi = modInverse(i, mod);
		
        ans = (ans%mod) * (a%mod)% mod;
        ans = (ans%mod) * (divi%mod) % mod;
       
    }
    
    return ans;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	
	long long n,m;
	long long mod = 1000000007;
	while(cin>>n>>m, n+m){
		cout<<ncr(n,m,mod)<<endl;
	}
	return 0;
}
