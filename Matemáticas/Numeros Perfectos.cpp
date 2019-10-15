#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/376/detalle/es


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int k; string s;
	
	while(cin>>k>>s){
		int n = s.size();
		int tabla_modular[n+2];
		tabla_modular[0] = 1;
		for(int i = 1; i<=n; i++){
			tabla_modular[i] = ((tabla_modular[i-1]%k) * (10%k) ) % k;
		}
		
		string es1 = "SI", es2="SI", es3="SI";
		string res ="";
		int p1= 0, p2 = 0, p3=1;
		for(int i = 0; i<n; i++){
			int digitos = n-i-1;
			int val = s[i]-'0';
			int u = ( (val%k) *(tabla_modular[digitos])) %k;
			p1+= u;  //divisor
			p2+= val; //suma
			p3*= val%k; //mult
		}
		p1=p1%k;
		p2=p2%k;
		p3=p3%k;
		if(p1)es1="NO";
		if(p2)es2="NO";
		if(p3)es3="NO";
		cout<<es1<<" "<<es2<<" "<<es3;
		
		if(p1==0 && p2==0 && p3==0)cout<<" PERFECTO"<<endl;
		else if(p1>0 && p2>0 && p3>0)cout<<" ABURRIDO"<<endl;
		else cout<<endl;

	}
	return 0;
}
