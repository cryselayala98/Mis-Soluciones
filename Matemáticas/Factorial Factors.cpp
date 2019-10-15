#include <bits/stdc++.h>
using namespace std;

//ccpl - 13 - 04 2018
//hallar factores primos del factorial de un numero
//limite n<=10**5

map<int, int>  factors [100005];
pair<int, int> p [100005];
const int MAX = 100005;
const int SQRT = 1000;
vector<int> primes;
bitset<MAX+1> marked;
bool pp[100005];

void sieve() {
    marked[1] = 1;
    int i = 2;
    for (; i <= SQRT; ++i) if (!marked[i]) {
        primes.push_back(i);
        for (int j = i*i; j <= MAX; j += i) marked[j] = 1;
    }
    for (; i <= MAX; ++i) if (!marked[i]) primes.push_back(i);
}

void primeFactors(int n) {
	//factors[n]= factors[n-1];
	int nn=n;
    for (int i = 0, p = primes[i]; p*p <= n; p = primes[++i]) {
    	/*if(factors[n].size()>0){
    		
    		continue;
    	}*/
        while (n % p == 0) {
            factors[nn][p]++;
            n /= p;
        }
    }
    if (n > 1)  factors[nn][n]++;
    
    
    p[nn] = p[nn-1];
    int primos_diferentes = 0;
	int total_primos = 0;
	for(auto x : factors[nn]){
		if(!pp[x.first]){
			primos_diferentes++;
			pp[x.first]=1;
		}
		 total_primos+=x.second;	
	}
	p[nn].first = p[nn].first + primos_diferentes;
	p[nn].second= p[nn].second + total_primos;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	//precalculo
	sieve();
	p[1].first = 0; p[1].second = 0;
	for(int i =2; i<100005; i++){
		primeFactors(i);
	}
	int t; cin>>t; int a;
	while(t--){
		cin>>a;
		cout<<p[a].first<<" "<<p[a].second<<endl;
	}
	
	return 0;
}
