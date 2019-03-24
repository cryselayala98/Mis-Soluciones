#include <bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/external/2/p294.pdf

map<int, int> factors(int n) {
	map<int, int> f;
	for (int x = 2; x*x <= n; x++) {
		while (n%x == 0) {
		f[x]++;
		n /= x;
		}
	}
	if (n > 1) f[n]++;
	
	return f;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n,a,b; cin>>n;
	
	while(n--){
		int nm=0, mm=0;
		cin>>a>>b; 
		
		for(int i = a; i<=b; i++){
			map<int, int>g = factors(i);
			long long divisores = 1; if(i==1)divisores =1;
			for(auto x : g){
				//cout<<x.first<<" "<<x.second<<endl;
				divisores*=x.second+1;
			}
			if(divisores>mm)mm=divisores, nm=i;
		//	cout<<i<<" tiene "<<divisores<<" divisores."<<endl;
		}
		cout<<"Between "<<a<<" and "<<b<<", "<<nm<<" has a maximum of "<<mm<<" divisors."<<endl;
	}
	return 0;
}