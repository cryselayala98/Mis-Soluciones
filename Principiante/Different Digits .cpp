#include <bits/stdc++.h>
using namespace std;
//https://vjudge.net/problem/UVA-12527

int prefix[5001];

bool verificar(int n){

    set<int>r;
    int actual = 0;
    while(n>0){
        actual = n%10;
        n/=10;
        int s = r.size();
        r.insert(actual);
        if(r.size()==s) return false;
    }
    return true;
}


void precalculo(){

    prefix[0]=1;
    for(int i =1; i<=5000; i++) prefix[i]= prefix[i-1] + (int)verificar(i);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    precalculo();
    int n,m;

    while(cin>>n>>m){
        int res = prefix[m]-prefix[n-1];
        cout<<res<<endl;
    }

    return 0;
}
