#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//https://codeforces.com/contest/1017/problem/A


int main() {
	int n; cin>>n;
	vector <int> j;
	int a,b,c,d;
	int i=1; int ji=1; int suma=0;
	while(n--){
		cin>>a>>b>>c>>d;
		j.push_back(a+b+c+d); 
		
		if(i==ji) suma = j[i-1];
		i++;
	}
	sort(j.rbegin(), j.rend());
	for(i=0; i<j.size(); i++){
		
		if(j[i]==suma){ cout<<(i+1)<<endl; break;}
	}
	return 0;
}