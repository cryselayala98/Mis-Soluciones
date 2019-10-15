#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/12/detalle/es

long long modpow(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        long long temp = modpow(a, b/2, mod);
        return (temp * temp) % mod;
    } else {
        long long temp = modpow(a, b-1, mod);
        return (temp * a) % mod;
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; string a; cin>>t;
	
	while(t--){
		cin>>a;
		long long num ;
		if(a.size()>1){
			num= stoi(a.substr(a.size()-2,2));
			if(num<2)num+=5;
		} 
		else num = stoi(a.substr(0,1));
		long long mod = modpow(66, num, 100);
		cout<<mod<<endl;
	}
	return 0;
}
