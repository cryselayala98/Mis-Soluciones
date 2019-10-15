#include <bits/stdc++.h>
using namespace std;
//http://trainingcenter.ufps.edu.co/problemas/396/detalle/es

int main() {

	int c; int a; 

    while(cin>>c){
        int maxi = 0;
        while(c--){
            cin>>a;
            maxi = max(maxi, a);
        } 
    if(maxi==0)cout<<"O(1)"<<endl;
    else if(maxi==1)cout<<"O(n)"<<endl;
    else cout<<"O(n^"<<maxi<<")"<<endl;
    }
	return 0;
}
