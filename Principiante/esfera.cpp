#include <bits/stdc++.h>
using namespace std;
# define M_PI           3.14159
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1011*/
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double t;
    cin>>t;
    
    double volumen= (4/3.0) * M_PI *pow(t,3);
    
    cout <<"VOLUME = "<< fixed << setprecision(3) << volumen << endl;
    
    return 0;}