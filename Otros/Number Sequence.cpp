#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//https://vjudge.net/problem/POJ-1019

template<class T>

string toString(const T &value) {
    ostringstream os;
    os << value;
    return os.str();
}

int main() {
	long long n; int t;
	cin>>t;
	
	while(t--){
		cin>>n; 
		long long ac= 0; 
		long long digitos = 0;
		string aux=""; 
	
		while(ac<n){
			digitos++;
			aux += toString(digitos);
			ac+=aux.size();
		}
		
		long long m = ac-aux.size();
		long long q = n-m;
		
		if(q==0)cout<<aux[aux.size()-1]<<endl;
		else cout<<aux[q-1]<<endl;
	}
	
	return 0;
}
