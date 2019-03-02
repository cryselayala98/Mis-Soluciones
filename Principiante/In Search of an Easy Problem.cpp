#include <bits/stdc++.h>
using namespace std;
//#define DEBUG
#define f first
#define s second
#define pb push_back
#define mp make_pair

//https://codeforces.com/contest/1030/problem/A

typedef long long ll;
typedef pair <int, int> p;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    #ifndef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int a; cin>>a;
    bool easy = 1;
	while(a--){
		int b; cin>>b;
		if(b==1)easy=0;
	}
		if(easy)cout<<"EASY"<<"\n";
		else cout<<"HARD"<<"\n";

    return 0;
}

