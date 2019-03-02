#include <bits/stdc++.h>
using namespace std;

int main() {
	int casos;
	string a;
	cin>>casos;
	
	while(casos--){
		cin>>a;
		int abre=0;
		bool valid=true;
		
		for(int i=0; i<a.size();i++){
		if(a[i]=='('){
		abre++;
		
		}else{
			if(abre>0){
			abre--;
			
			}else{
				valid=false; break;
			}
			
		}
		}
		if(abre==0 && valid)cout<<"CORRECTO";
		else cout<<"INCORRECTO";
		
		cout<<endl;
			
		
	}
	return 0;
}