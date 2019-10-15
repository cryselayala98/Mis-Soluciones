#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/319/detalle/es

int p = 265; 
int MOD = 1000000009; 

struct hashing {
	string s;
	int h[10005], pot[10005];
	hashing(string _s) {
		s = _s; h[0] = 0; pot[0] = 1;
		for(int i = 1; i <= s.size(); i++) {
			h[i] = ((long long)h[i - 1] * p + s[i - 1]) % MOD;
			pot[i] = ((long long)pot[i - 1] * p) % MOD;
		}
	}
	int hashValue(int i, int j) {
		int ans = h[j] - (long long) h[i] * pot[j - i] % MOD;
		return (ans >= 0) ? ans : ans + MOD;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	
	int n; cin>>n;
	
	string a; int q, i,j;
	while(n--){
		cin>>a>>q;
		hashing aux (a);
		int r = a.size();
		reverse(a.begin(), a.end());
		hashing aux_invertido(a);
		while(q--){
			cin>>i>>j;
			if(aux.hashValue(i,j)==aux_invertido.hashValue(r-j+1, r-i+1))cout<<"Palindromo"<<endl;
			else cout<<"No palindromo"<<endl;
		}cout<<endl;
	}
	return 0;
}
