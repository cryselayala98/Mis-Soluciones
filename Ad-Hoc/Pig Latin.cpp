#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n; string str, n1;
	cin>>n;
	getline(cin,n1);
	while(n--){
		getline(cin, str);
		istringstream iss(str);
		string  subs;
		bool es = 0;
		while (iss >> subs) {
			if(es)cout<<" ";
			es = 1;
			rotate(subs.begin(), subs.begin() + 1, subs.end());
			if(subs[subs.size()-1]<=90) {
				subs[subs.size()-1] = tolower(subs[subs.size()-1]);
				subs[0] = toupper(subs[0]);
			}
			cout<<subs<<"ay";
		}
		cout<<"\n";
		
	}
	return 0;
}