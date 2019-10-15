#include<bits/stdc++.h>
using namespace std;
#define EPSILON 1e-10

//https://vjudge.net/problem/UVA-11881

vector <double> cf;
int t;

 
double funcion(double irr){
    
    double r = 0.0;
    
    for(int i = 0; i< t; i++) r+=cf[i] / (pow(1+irr , i));

    return r;
}
 

double bisection(long double a, long double b){

    double m = (a+b)/2.0;
    if(abs(funcion(m))<EPSILON)return m;
    if(funcion(a)*funcion(m) < 0.0) return bisection (a,m);
    else return bisection (m,b);
    
}
 

int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<fixed<<setprecision(2);
	while(cin>>t, t){
	    cf.clear();
	    long double a;
	    for(int i = -1; i< t; i++){
		    cin>>a;
		    cf.push_back(a);
	    }
	    t++;
	    cout<<bisection(-1.0, 100000000)<<endl;
	}
    
    return 0;
}
