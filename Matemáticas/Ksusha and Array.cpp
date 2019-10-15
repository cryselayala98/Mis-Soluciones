#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/CodeForces-299A


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n;
	
	while(cin>>n){
		vector<int> vals;
		while(n--){
			int a; cin>>a;
			vals.push_back(a);
		}
		sort(vals.begin(), vals.end());
		
		int g= vals[0];
		for(int i =1; i<vals.size(); i++){
			g=gcd(g, vals[i]);
		}
		if(binary_search(vals.begin(), vals.end(), g)) cout<<g<<endl;
		else cout<<-1<<endl;
		}
	
	
	return 0;
}
