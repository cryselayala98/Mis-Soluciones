#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/389/detalle/es

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	
	long long a,b,c,d; string op;
	while(cin>>a>>b>>op>>c>>d){
		long long e,f;
		if(op =="+") e = (a*d)+(b*c), f = (b*d);
		else if(op =="-") e = (a*d)-(b*c), f = (b*d);
		else if(op =="*") e = (a*c), f = (b*d);
		else e = (a*d), f = (b*c);
		
		//simplificar
		
		long long divi = gcd(e,f);
		
		while(divi>1){
			e/=divi, f/=divi;
			 divi = gcd(e,f);
		}
		
		cout<<e<<" "<<f<<endl;
	}
	return 0;
}
