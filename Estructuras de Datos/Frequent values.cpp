#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

//https://vjudge.net/problem/UVA-11235

map<int,pair <int, int> >  rango;

class SegmentTree {         
private: vector<int> st, A;            
  int n;
  int left (int p) { return p << 1; }     
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) { 
    if (L == R) 
      st[p] = L;
    else { 
      build(left(p) , L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] >= A[p2]) ? p1 : p2;
    } 
  }

  int rmq(int p, int L, int R, int i, int j) { 
    if (i >  R || j <  L) return -1; 
    if (L >= i && R <= j) return st[p]; 
    int p1 = rmq(left(p) , L, (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R, i, j);

    if (p1 == -1) return p2;   
    if (p2 == -1) return p1; 
    return (A[p1] >= A[p2]) ? p1 : p2; } 

public:
  SegmentTree(const vector<int> &_A) {
    A = _A; n = (int)A.size();
    st.assign(4 * n, 0);   
    build(1, 0, n - 1);
  }

  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }


};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,a,b;
	
	while(cin>>n,n){
		rango.clear();
		cin>>m;
		
		int arr[n], arr2[n];
		int aux =1; int k; cin>>k; int ini = -1;
		arr2[0] = k;
		
		for(int i=0; i<n-1; i++){
			cin>>a;
			arr2[i+1]= a;
			if(a!=k){
			rango[k] = make_pair(ini+1, ini+aux);
			
			for(int j = ini+1; j<=ini+aux ; j++) arr[j] = aux;
			ini+=aux;
			aux=1;
			k=a;
			}else aux++;
			
		} for(int j = ini+1; j<=ini+aux ; j++) arr[j] = aux;
		  rango[k] = make_pair(ini+1, ini+aux);
		
		  vector<int> A(arr, arr + n);                  
		  SegmentTree st(A);
	    int res;
	    while(m--){
	    	res= 0;
	    	cin>>a>>b;
	    	a--; b--;
	    	
	    	//extremos
	    	pair <int , int> r = rango[arr2[a]];
	    	
	    	int rep= min(b, r.s )- a + 1;
	    	a+= rep;
	    	res = max(res, rep);
	    	r = rango[arr2[b]];
	    	rep = b - max(r.f, a) + 1;
	    	
	    	b-=rep;
	    	res = max(res, rep);
	    if(a<=b) res = max(res, arr[st.rmq(a,b)]);
	    cout<<res<<"\n";
	    }
	    
	}
	
	return 0;
}