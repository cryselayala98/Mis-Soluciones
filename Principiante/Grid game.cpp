#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1104/problem/C

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	string a; cin>>a;
	
	bool cero= 0, uno = 0;
	
	for(char i : a){
		if(i=='0'){
			if(cero){
				cout<<"1 1\n";
				cero = 0;
			}else{
				cout<<"3 1\n";
				cero = 1;
			}
		}else{
			if(uno){
				cout<<"1 1\n";
				uno = 0;
			}else{
				cout<<"1 3\n";
				uno = 1;
			}
		}
	}
	
	return 0;
}