#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/277/detalle/es

int main() {
	int casos; string str;
	cin>>casos;
	getline(cin, str);
	while(casos--){
		getline(cin, str);
		string res = "";
		string actual ;
		istringstream iss(str);
		string subs;
		while (iss >> subs) {
			if(res!="")res+=" ";
			actual = subs;
			res+= subs;
		}
		

			for(int i = res.size()-1; i>=0; i--){
				if(res[i]!='?' && res[i]!='.' && res[i]!='!'){
					string res1="hhhhh"+res.substr(0,i+1);
				
					if(res1.substr(res1.size()-3, 3)!="bro"){
						res=res.substr(0,i+1)+" bro"+res.substr(i+1, res.size());
					}
					break;
				}
			}
		
	

		cout<<res<<endl;
	}

	return 0;
}
