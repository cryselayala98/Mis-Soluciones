#include <bits/stdc++.h>
using namespace std;
/*http://trainingcenter.ufps.edu.co/#/problemas/4/detalle/es*/

int main() {
	// your code goes here
int y;
cin>> y ;
double x1, y1, x2, y2, d, c;
while(y--) {

cin>>x1>>y1>>x2>>y2>>d>>c;

double distancia  = sqrt (  pow( abs(x2-x1), 2  ) +   pow(abs(y2-y1), 2  )  ) ;

double t = distancia  /   c;

if(t<=d) {
cout<<"si" <<endl;
} else{
cout<<"no"<<endl;
} 
} 
	return 0;
}