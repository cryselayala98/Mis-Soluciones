#include <bits/stdc++.h>
using namespace std;

int main() {
	int cases;
	cin>>cases;
	int n;

	while(cases--){
		int y=0;
		int cont=0;
		cin>>n;
	
		for (int divisor= 1234; divisor<=98765; divisor++ ){
	
			int dividendo= divisor*n;
		
			if(dividendo>=10000 && dividendo<99999){
			string f="";
		//	int r= dividendo*10000+divisor;
			stringstream convert; 
			convert << dividendo;
			f+=  convert.str();
			stringstream convert2; 
			convert2 << divisor;
			f+=  convert2.str();
			bool activado[10];
			
			memset(activado, false, sizeof(activado));
			int a=0;
			if(divisor<10000){
				a++;
				activado[0]=true;
			}
		//	cout<< dividendo<<" / "<<"0"<<divisor<<" = "<<n<<endl;
				int sumadig=0;
			//	cout<<f<<endl;
				for(int i=0; i<f.size(); i++){
			//	if(divisor<10000 && f[i]=='0'){
			//		break;
			//	}
					
					int uva= f[i]-48;
					if(!activado[uva]){
					sumadig=sumadig+(uva);
					activado[uva]=true;
					a++;
					}else{
					break;	
					}
				
					
				} 
			//	cout<<sumadig<<endl;
				if(a==10){
				cont++;
				
					cout<<"dividendo = "<<dividendo<<" y divisor = ";
					if(divisor<10000){
						cout<<"0";
					}
					cout<<divisor<<endl; 
				}	
				
			
				
			}
		
			
			
			
		}
		
		if(cont<1){
		cout<<"IMPOSIBLE"<<endl;
		
		}
		if(cases!=0)cout<<endl;

}
	return 0;
}