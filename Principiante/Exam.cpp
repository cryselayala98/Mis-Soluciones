#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/101982 ejercicio a

int main() {
	int correctas; cin>>correctas;
	string a; string b; cin>>a>>b;
	int total = a.size(); 
	int iguales=0;
	for(int i =0; i<total; i++){
		if(a[i]==b[i])iguales++;
	}
	int r= abs(iguales - correctas);
	cout<<(total - r)<<endl;
	
	return 0;
}