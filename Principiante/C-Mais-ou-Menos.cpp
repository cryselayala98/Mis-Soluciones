#include <bits/stdc++.h>
using namespace std;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/2486*/

static int cant(string fruta){
    

        
        if(fruta== " suco de laranja") return 120;
         if(fruta==  " morango fresco" ) return 85;
         if(fruta== " mamao" ) return 85;
     if(fruta==" goiaba vermelha") return 70;
         if(fruta== " manga") return 56;
          if(fruta== " laranja") return 50;
       return 34;
    
    
    
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int frutas=1;
    while(cin>>frutas ){
    	if(frutas==0){break;
    		}
        int total=0;
        while(frutas-->0){
            int can;
            string fruta;
            cin>>can;
            getline(cin, fruta);
            total=total+( can * cant(fruta));
            
        }
        if(total>130){
            total=total-130;
            cout <<"Menos "<< total<<" mg"<<"\n";
        }else if(total<110){
             total=110-total;
            cout <<"Mais "<< total<<" mg"<<"\n";
        }else{
             cout << total<<" mg"<<"\n";
        }
        
    }
    
    return 0;
}