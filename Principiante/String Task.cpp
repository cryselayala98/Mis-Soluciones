#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/236459/problem/A

int main() {
	string a; cin>>a;
	for(int i =0; i<a.size(); i++){
		a[i]= tolower(a[i]);
		if(a[i]!= 'y' && a[i]!='a' && a[i]!='e' && a[i]!='i' && a[i]!='o'&& a[i]!='u')
		cout<<"."<<a[i];
	}cout<<endl;
	return 0;
}