#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979323846

//https://trainingcenter.cloud.ufps.edu.co/problemas/387/detalle/es

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	long double l,h;
	while(cin>>l>>h){
		long double a = (h*0.5)/(sin(pi/3.0));
		long long y = (long long)ceil((l/a))+1;
		cout<<y<<endl;
	}
	return 0;
}
