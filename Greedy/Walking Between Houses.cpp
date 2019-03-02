#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1015/problem/D

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	long long n,k,s; cin>>n>>k>>s;
	vector<long long>pasos;
	long long cont =0; 
	
	
	if(s%(n-1)){
		pasos.push_back(s%(n-1));
	}
	cont+= s / (n-1);
	
	if(cont+pasos.size()>k || s<k)cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		
		long long pasos_tam_1 = 0; long long acum;
		
		while(cont + pasos.size() + pasos_tam_1<k){
			long long val ;
			if(cont){
				val = n-1;
				cont--;
				acum = cont + pasos.size() + pasos_tam_1;
			}else{
				sort(pasos.rbegin(), pasos.rend());
				val = pasos[0];
				pasos.erase(pasos.begin());
				acum = pasos.size() + pasos_tam_1;
			}
			
			
				if(acum + val<= k){
					pasos_tam_1 += val;
				}else{
					long long sob = acum + val - k + 1;
					pasos_tam_1 += val - sob;
					pasos.push_back(sob);
					break;
				}
		}
		sort(pasos.rbegin(), pasos.rend());
	
		int u = 1;
		for(int i = 0; i<cont; i++){
			if(i)cout<<" ";
			if(i%2==0)u+=n-1;
			else u-=n-1;
			cout<<u;
		}
		
		for(int i = 0; i<pasos.size(); i++){
			if(i+cont)cout<<" ";
			if((i+cont)%2==0)u+=pasos[i];
			else u-=pasos[i];
			cout<<u;
		}
		for(int i = cont + pasos.size(); i<cont + pasos.size()+pasos_tam_1; i++){
			if(i)cout<<" ";
			if(i%2==0)u++;
			else u--;
			cout<<u;
		}
		
		cout<<endl;
		
	}
	
	return 0;
}