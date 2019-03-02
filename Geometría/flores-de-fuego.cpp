#include <bits/stdc++.h>
using namespace std;

//https://www.urionlinejudge.com.br/judge/es/runs/code/8308047

double euclideanDistance(double x1, double y1, double x2, double y2){           
 // return sqrt((x2-x1)*(x2-x1)+ (y2-y1)*(y2-y1)); 
 return hypot(x1 - x2, y1 - y2); 
} 


int main() {
double x1, y1, x2, y2;
int r1, r2;
while(cin>>r1>>x1>>y1>>r2>>x2>>y2){

double dist= euclideanDistance(x1, y1, x2, y2) ;
//cout<<dist<<endl;
dist+=r2;
//cout<<dist<<endl;

if(dist<=r1){
	cout<<"RICO"<<endl;
}else{
	cout<<"MORTO"<<endl;
}
	
}
	return 0;
}