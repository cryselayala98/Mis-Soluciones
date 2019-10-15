#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/54/detalle/es
//string adhoc

int main() {
	
	int casos;
	cin>>casos;
	int h,w, vertical, horizont;
	while(casos--){
		
		cin>> h>>w>> vertical>>horizont;
		vertical--; horizont--;
		//para la linea 0
		cout<<" ";
		for(int i=0;i<w; i++){
			 cout<<"_";
			 if(i==vertical) cout<<" ";
		}
		cout<<endl;
		
		//para las demas :v
	for(int j=0; j<h; j++){
			cout<<"|";
			
		for(int i=0;i<w; i++){
			
			if (j==horizont || j==h-1){ cout<<"_";}
		
			else cout<<" ";
			
		          if(i==vertical) cout<<"|";
		}
		cout<<"|"<<endl;
		}
		
		cout<<endl;
	}
	return 0;
}
