#include <bits/stdc++.h>
using namespace std;
//https://www.urionlinejudge.com.br/judge/es/problems/view/1162

int main() { 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);




    float salario, imposto;
    cin >> salario;

    
    if(salario<=2000.00){cout << "Isento"<< endl;}
    else if ( salario >= 2000.01 && salario <= 3000) {

    imposto = (salario-2000) * 0.08;
    cout <<"R$ "<< fixed << setprecision(2) << imposto<< endl ; }

        else if ( salario >= 3000.01 && salario <= 4500) {

    imposto = (1000*0.08) + ((salario-3000)*0.18);
     cout <<"R$ "<< fixed << setprecision(2) << imposto<< endl; }

            else if ( salario > 4500) {

    imposto = (1000*0.08) + (1500*0.18) + ((salario-4500)*0.28);
     cout <<"R$ "<< fixed << setprecision(2) << imposto << endl; }

                

    return 0;

}

