#include <bits/stdc++.h>
using namespace std;

int main() {
	int casos, n, a;
	
	cin>>casos;
	
	while(casos--){
		cin>>n;
		map <int, int> horas;
		while(n--){
			cin>>a;
			if(!horas.count(a))horas[a]=0;
			else horas[a]=horas[a]+1;
		} 
		
		int temprano=horas.begin()->first; int tarde=horas.rbegin()->first;
		
		cout<<"Horas diferentes: "<<horas.size()<<endl;
		cout<<"Temprano: "<<(temprano/60)<<":"<<temprano-( 60* (temprano/60))<<endl;
		cout<<"Tarde: "<<(tarde/60)<<":"<<tarde-( 60* (tarde/60))<<endl;
	}
	return 0;
}