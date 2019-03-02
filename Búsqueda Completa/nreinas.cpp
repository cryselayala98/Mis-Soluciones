#include <bits/stdc++.h>
using namespace std;

bool fila[9], diagder[30], diagizq[30];
int n=8;
//int cont=0;
bool sihay=false;
void search (int col, string a){
	
	if(col==n){
		cout<<a<<endl;
		sihay=true;
	//	cont++;
		return;
	}
	
	for(int fil=0; fil<n; fil++){
		if(!fila[fil] && !diagder[fil-col+n-1] && !diagizq[fil+col]){
			fila[fil]=true;
			diagder[fil-col+n-1]=true;
			diagizq[fil+col]=true;
			
			stringstream convert; 
			convert << fil+1;
			string f=  convert.str();
			//cout<<a+f<<endl;
			search(col+1, a+f);
			
			fila[fil]=false;
			diagder[fil-col+n-1]=false;
			diagizq[fil+col]=false;
		}
		
	}
	
}

int main() {
	
	int casos;
	cin>>casos;
	
	
	while(casos--){
//	cont=0;
	cin>>n;
	sihay=false;
	
	memset(fila, false, sizeof(fila));
	memset(diagder, false, sizeof(diagder));
	memset(diagizq, false, sizeof(diagizq));
	
	search(0, "");
	if(!sihay){
	cout<<"IMPOSIBLE"<<endl;	
	}
		
	//	cout<<cont<<endl;
		if(casos!=0){
			cout<<endl;
		}
	}
	return 0;
}