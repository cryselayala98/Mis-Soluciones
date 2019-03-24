#include <bits/stdc++.h>
using namespace std;

//http://coj.uci.cu/24h/problem.xhtml?pid=1812

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	map<string, int> mapita; 
	mapita["Ka"]=1;
	mapita["Ro"]=1;
	mapita["Pi"]=1;
	mapita["St"]=1;
	mapita["Ko"]=1;
	mapita["Ko"]=1;
	mapita["Sa"]=1;
	mapita["Ro"]=1;
	mapita["Gu"]=1;
	mapita["Ka"]=1;
	mapita["Pi"]=1;
	
	mapita["Nu"]=2;
	mapita["Sc"]=2;
	mapita["Ci"]=2;
	mapita["Sc"]=2;
	mapita["Ol"]=2;
	mapita["Ol"]=2;
	mapita["Fo"]=2;
	mapita["Ch"]=2;
	mapita["No"]=2;
	mapita["Ti"]=2;
	
	mapita["Pa"]=3;
	mapita["Pa"]=3;
	mapita["Fe"]=3;
	mapita["Pa"]=3;
	mapita["Pa"]=3;
	mapita["Ca"]=3;
	mapita["Re"]=3;
	mapita["Pa"]=3;
	
	string a,b,c,d;
	
	//1 rock | scissors 2 |  paper 3
	string e,f; int g=1;
	int j1=0; int j2=0;
	while(true){
		cin>>a>>b>>c>>d;
		 j1=0;  j2=0;
		while(cin>>e){
			if(e==".")goto final;
			else if(e=="-")break;
			else{
			cin>>f;
		//	cout<<e<<" "<<f<<endl;
			string ee= e.substr(0,2); string ff= f.substr(0,2);
			//cout<<ee<<" "<<ff<<endl;
			int  j11 = mapita[ee], j22= mapita[ff];
			if(j11==1 && j22==2)j1++;
			if(j11==2 && j22==1)j2++;
			
			 if(j11==2 && j22==3)j1++;
			 if(j11==3 && j22==2)j2++;
			
			if(j11==3 && j22==1)j1++;
			if(j11==1 && j22==3)j2++;
		}
		}
		string po1= " point", po2= " point";
		if(j1!=1)po1=" points"; if(j2!=1)po2=" points";
		
		cout<<"Game #"<<g<<":"<<"\n";
		cout<<b<<": "<<j1<<po1<<"\n";
		cout<<d<<": "<<j2<<po2<<"\n";
		
		if(j1==j2) cout<<"TIED GAME"<<"\n";
		else if(j1>j2)cout<<"WINNER: "<<b<<"\n";
		else cout<<"WINNER: "<<d<<"\n";
		g++;
		cout<<endl;
	}
	final:
		string po1= " point", po2= " point";
		if(j1!=1)po1=" points"; if(j2!=1)po2=" points";
		
		cout<<"Game #"<<g<<":"<<"\n";
		cout<<b<<": "<<j1<<po1<<"\n";
		cout<<d<<": "<<j2<<po2<<"\n";
		
		if(j1==j2) cout<<"TIED GAME"<<"\n";
		else if(j1>j2)cout<<"WINNER: "<<b<<"\n";
		else cout<<"WINNER: "<<d<<"\n";
		cout<<"\n";
	
	return 0;
}