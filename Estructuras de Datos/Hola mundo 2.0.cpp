#include <bits/stdc++.h>
using namespace std;

//https://trainingcenter.cloud.ufps.edu.co/problemas/392/detalle/es

int main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif

    int personas; cin>>personas;
    map<string, int> apariciones; queue <string>p;

    while(personas--){
        string a; cin>>a;
        p.push(a);
        apariciones[a]++;
    }
    while(p.size()){
        string actual = p.front();
        p.pop();
        if(apariciones[actual]>1)apariciones[actual]--;
        else cout<<"Hola "<<actual<<endl;
    }
    
	
	return 0;
}
