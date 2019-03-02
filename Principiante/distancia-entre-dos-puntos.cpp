#include <bits/stdc++.h>
using namespace std;

//https://www.urionlinejudge.com.br/judge/es/problems/view/1014

int main(){

double x1, y1, x2, y2;

cin >> x1>>y1>>x2>>y2;
double z = sqrt( pow( (x2 - x1) , 2 ) + pow ( (y2 - y1), 2 ) );
cout << fixed << setprecision(4) << z<<endl;

return 0;
}
