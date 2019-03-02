#include <bits/stdc++.h>
using namespace std;


int main() {
	
	int casos;
	cin>>casos;
	
	
while(casos--){
	int sumas[7];
	memset(sumas, 0, sizeof(sumas));
	int s;
	cin>>s;
	
	while(s--){
	int i=0;
	int a;
	while(i<7){
		cin>>a;
		sumas[i]+=a;
		i++;
	}
	}
	int menor =100;
	for(int j=0; j<7;j++){
		if(sumas[j]<menor){
			menor=sumas[j];
		}
	}
	cout<<menor<<endl;
}
	return 0;
}
                    