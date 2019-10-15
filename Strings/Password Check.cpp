#include <bits/stdc++.h>
using namespace std;

//string adhoc
//https://vjudge.net/contest/300253#problem/C

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	string a; cin>>a;
	
	int r1 =0, r2=0, r3=0, r4=0;
	if(a.size()>=5)r1++;
	for(auto x:a){
		if(x>='A' && x<='Z')r2++;
		else if(x>='a' && x<='z')r3++;
		else if(x>='0' && x<='9')r4++;
	}
	if(r1 && r2 && r3 && r4)cout<<"Correct\n";
	else cout<<"Too weak\n";
	return 0;
}