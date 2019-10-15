#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

//https://vjudge.net/problem/UVA-12366

vector <pair<int, pair<int, int> > > hands;
map <pair<int, pair<int, int> >, int> query;

void precalculo(){
    //pairs
    for(int i = 1; i<=13; i++){
        for(int j = 1; j<=13; j++){
            if(j!=i){
               pair<int, pair<int, int> > x = make_pair(i, make_pair(i,j));
               hands.push_back(x);
               query[x]=hands.size();
            }
        }


    }
    //sets
    for(int i = 1; i<=13; i++){
        pair<int, pair<int, int> > x = make_pair(i, make_pair(i,i));
        hands.push_back(x);
        query[x]=hands.size();
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    precalculo();
    int a, b, c;
    while(cin>>a>>b>>c, a+b+c){
        if(a!=b && a!=c && b!= c)cout<<"1 1 2"<<endl;
        else if(a==13 &&b==13 && c==13){
                cout<<"*"<<endl;
        }else{
            vector<int>vals;
            vals.push_back(a);
            vals.push_back(b);
            vals.push_back(c);
            sort(vals.begin(), vals.end());

            if(vals[1]==vals[2]){
                swap(vals[0],vals[2]);
            }

            pair<int, pair<int, int> > ww = hands[query[make_pair(vals[0], make_pair(vals[1],vals[2]))]];

            vals.clear();
            vals.push_back(ww.f);
            vals.push_back(ww.s.f);
            vals.push_back(ww.s.s);
            sort(vals.begin(), vals.end());
            cout<<vals[0]<<" "<<vals[1]<<" "<<vals[2]<<endl;
        }

    }
    return 0;
}

