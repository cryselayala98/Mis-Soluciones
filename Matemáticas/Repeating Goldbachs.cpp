#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/101982 ejercicio h

const int MAX = 1000002;
const int SQRT = 1000;
vector<int> primes;
bitset<MAX+1> marked;

void sieve() {
    marked[1] = 1;
    int i = 2;
    for (; i <= SQRT; ++i) if (!marked[i]) {
        primes.push_back(i);
        for (int j = i*i; j <= MAX; j += i) marked[j] = 1;
    }
    for (; i <= MAX; ++i) if (!marked[i]) primes.push_back(i);
}


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	marked.reset();
	sieve();
	
	int r; cin>>r;
	int cy=0;
	
	while(r>4){
		int i=0;
		int p = primes[i]; int q= r-p; 
		while(marked[q]){
			i++; p = primes[i];
			q= r-p; 
		}
		r=q-p;
		cy++;
	}
	if(r==4)cy++;
	
	cout<<cy<<endl;
	return 0;
	
}