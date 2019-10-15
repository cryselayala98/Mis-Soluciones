#include <bits/stdc++.h>
using namespace std;

//http://trainingcenter.ufps.edu.co/clases/tarea/58/problema/186/290/es

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	int c; cin>>c; int x1,y1,x2,y2;
	while(c--){
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2)cout<<"Recta paralela al eje Y"<<endl;
		else if(y1==y2)cout<<"Recta paralela al eje X"<<endl;
		else cout<<"Recta no paralela a ningun eje"<<endl;
	}
	return 0;
}
