#include <bits/stdc++.h>
using namespace std;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/2165*/

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a;
    getline(cin, a);
    if(a.size()<=140){
        cout<<"TWEET"<<"\n";
    }else {
        cout<< "MUTE"<<"\n";
    }
    return 0;
}