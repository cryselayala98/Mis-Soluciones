#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int casos, n;
	string a;
	
	cin>>casos;
	
	while(casos--){
		vector<string> pala;
		cin>>n;
		while(n--){
		cin>>a; pala.push_back(a);	
		}
		
		sort(pala.begin(), pala.end());
		
		for(string pala1 : pala){
			cout<<pala1<<"\n";
		} cout<<"-\n";
	}
	return 0;
}