#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
	int n, k;
	string s;
	cin>>n>>k>>s;
	map<char, int> mapa;
	for(int i=0; i<n; i++){
		mapa[s[i]]++;
	}
	
	for(auto c: mapa){
		if(k<=0) break;
		int aux = c.second;
		mapa[c.first] -= k;
		k -= aux;
	}
	string ans = "";
	for(int i=n-1; i>=0;i--){
		if(mapa[s[i]] >0){
			mapa[s[i]]--;
			ans+= s[i];
		} 
	}
	s = "";
	for(int i=ans.size()-1; i>=0; i--) s+=ans[i]; 
	cout<<s<<endl;
	return 0;
}