#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/101972/problem/A

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	long long c, a,b;
	cin>>c;
	while(c--){
		cin>>a>>b;
		vector<long long> vals_a, vals_b;
		
		long long val=1;
		
		while(a!=0){
			long long s =a%10*val;
			if(s!=0)vals_a.push_back(s);
			a=a/10;
			val*=10;
		}
		
		val=1;
		
		while(b!=0){
			long long s =b%10*val;
			if(s!=0)vals_b.push_back(s);
			b=b/10;
			val*=10;
		}
		
		for(int i = 0; i< vals_a.size(); i++){
			for(int j = 0; j< vals_b.size(); j++){
			if(i!=0 || j!=0)cout<<" + ";
			cout<<vals_a[i]<<" x "<<vals_b[j];
			}
		}
		cout<<endl;
	}
	return 0;
}