#include <bits/stdc++.h>
using namespace std;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/2116*/

vector<int> criba_eratostenes(int n)
{
    vector<int> criba;
    int current_primo;  
    for (int i = 2; i <= n; i++)
        criba.push_back(i);
        
    if (n == 2 || n == 3) 
        return criba;
    vector<int>::iterator it = criba.begin();
    current_primo = *it;  
    do {
        vector<int>::iterator it2 = it + 1;

        for(; it2 <= criba.end(); it2++)
            if(*it2 % current_primo == 0)
                criba.erase(it2);

        it++;
        current_primo = *it;

    } while (pow(current_primo, 2) < n);

    return criba;
}
int main() {
  
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    
    cin>> N; 
            cin>> M;
    vector <int>v1= criba_eratostenes(M);
    vector <int>v2=criba_eratostenes(N);
    
    

    int k=v1[v1.size()-1]*v2[v2.size()-1];
    cout<< k<<"\n"; 

    return 0;
}