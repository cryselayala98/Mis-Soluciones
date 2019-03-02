#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1003/problem/C


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n; double k;
	cin>>n>>k;
	
	double vals[n];
	
	for(int i = 0; i< n; i++)cin>>vals[i];
	
	double max_t=0.0;
	
	for(; k<=n; k++){
		
			double acum= 0.0; 
	for(int i = 0; i<k; i++)acum+= vals[i];
	max_t= max(max_t, acum / k);
	
	
	for(int i = 0; i<n-k; i++){
	
		acum= acum-vals[i]+vals[i+(int)k];
		max_t =max(max_t, acum / k);
	}
	
	
	}
	cout << fixed << setprecision(10) << max_t << endl;

	return 0;
}