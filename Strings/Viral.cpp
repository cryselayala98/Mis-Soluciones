#include <bits/stdc++.h>
using namespace std;

//string adhoc, tc
//https://trainingcenter.cloud.ufps.edu.co/problemas/379/detalle/es

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	string a; 
	while(cin>>a){
		vector <char> vars;
		for(int i =0; i<a.size(); i++) vars.push_back(a[i]);
		
		bool es = 1;
		int cnt = 1;
		char act = vars[0];
		for(int i =1; i<vars.size(); i++){
			if(vars[i]==act){
				cnt++;
			}else{
				cnt=1;
				act= vars[i];
			}
			if(cnt==3){
				cnt= 0;
				act='#';
				int u = i-2;
				for(int j = 0; j<3; j++)vars.erase(vars.begin()+u);
				i = -1;
			}
		}
		
		if(vars.size()>0)es= 0;
		if(es)cout<<"SI"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
