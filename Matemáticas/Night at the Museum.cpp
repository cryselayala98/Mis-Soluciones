#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/375/detalle/en

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	string a;
	
	while(cin>>a){
		int t= 0;
		
		char act = 'a';
		for(int i = 0;i<a.size(); i++){
			int e= min(abs(a[i]-act), 26-abs(a[i]-act));
			t+=e;
			act=a[i];
		}
		cout<<t<<endl;
	}
	return 0;
}
