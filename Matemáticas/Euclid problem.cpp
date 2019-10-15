#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-10104

int x, y, d;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int extendedEuclid(int a, int b) {
    if(b == 0) { x = 1; y = 0; return a; }
    d = extendedEuclid(b, a % b);
    int temp = x;
    x = y;
    y = temp - (a/b)*y;
    return d;
}

int main() {
	int a;
	int b;
	int d;
	while(cin>>a>>b){
	    extendedEuclid(a, b);
	    d=gcd(a,b);
	    cout<<x<<" "<<y<<" "<<d<<endl;
	}

	return 0;
}
