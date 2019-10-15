#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair

//https://codeforces.com/gym/100540/attachments ejercicio j

typedef long long ll;
typedef pair <int, int> p;

long long pot[100005];
vector<pair<long long, pair<int, int> > > conjs; ///almacena los subconjuntos de rangos que entran en una consulta 

class SegmentTree {         
private: vector<long long> st; 
  long long mod, b;           
  int n;
  int left (int p) { return p << 1; }     
  int right(int p) { return (p << 1) + 1; }

  void solve(int p, int L, int R, int i, int j) { 
    if (i >  R || j <  L) return; 
    if (L >= i && R <= j){ conjs.pb(mp(st[p], mp(L,R))); return ;}
	
	solve(left(p) , L, (L+R) / 2, i, j);
	solve(right(p), (L+R) / 2 + 1, R, i, j);
    } 

  long long update_point(int p, int L, int R, int idx, long long new_value) {
    int i = idx, j = idx;

    if (i > R || j < L) return st[p];
  
    if (L == i && R == j) return st[p] = new_value; 
	
    long long p1, p2;
    p1 = update_point(left(p) , L, (L + R) / 2, idx, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R, idx, new_value);
	
    return st[p] = (p1* pot[R  - ((L + R) / 2) ]+ p2 )% mod;
  }

public:
  SegmentTree(int c,long long p, long long g) {
    n = c; mod = p; b = g;
    st.assign(4 * n, 0);
  }

  void solve(int i, int j) { solve(1, 0, n - 1, i, j); }

  long long update_point(long long idx, long long new_value) {
    return update_point(1, 0, n - 1, idx, new_value); }
};

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	
	long long b,p,l,n,a,bb; char val;
	while(cin>>b>>p>>l>>n, b){
		pot[0]=1;
		for(int i = 1; i<l; i++) pot[i] = pot[i-1] * b % p;
		
		SegmentTree st(l, p, b);
		while(n--){
			cin>>val>>a>>bb;
			if(val =='E'){
				st.update_point(a-1, bb);
			}else{
				conjs.clear();
				st.solve(a-1, bb-1);
				long long res=0, cont_pot=0;
				for(int i = conjs.size()-1; i>=0; i--){
					
					res = (conjs[i].f * pot[cont_pot] + res )% p;
					cont_pot+= conjs[i].s.s - conjs[i].s.f + 1;
					
				}
				cout<<res<<"\n";
			}
		} cout<<"-\n";
		
	}
    


    return 0;
}
