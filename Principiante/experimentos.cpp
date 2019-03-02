#include <bits/stdc++.h>
 
using namespace std;

/*https://www.urionlinejudge.com.br/judge/es/problems/view/1094*/
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
     int casos;
     double cantidad;
     char c;
     cin>>casos;
     
     double coelhos, ratos, sapos = 0;
     
     while(casos--){
     
	cin>>cantidad;	
     	cin  >> c;
     	
     	
     	if(c=='C'){
     	 coelhos+= cantidad;	
     	}else if (c=='R'){
     	 ratos+=cantidad;
     	}else{
     	 sapos+=cantidad;
     	}
     }
     double total= coelhos+ratos+sapos;
     
     cout<<"Total: "<< fixed << setprecision(0) << total << " cobaias\nTotal de coelhos: "<<fixed << setprecision(0) << coelhos <<"\nTotal de ratos: "
     <<fixed << setprecision(0) << ratos <<"\nTotal de sapos: "<<fixed << setprecision(0) << sapos  <<"\nPercentual de coelhos: "<<fixed << setprecision(2) <<(coelhos*100)/total <<" %\nPercentual de ratos: "<<
     fixed << setprecision(2) << (ratos*100)/total <<" %\nPercentual de sapos: "<<fixed << setprecision(2) << (sapos*100)/total <<" %\n";
     
     
    

   
 
    return 0;
}