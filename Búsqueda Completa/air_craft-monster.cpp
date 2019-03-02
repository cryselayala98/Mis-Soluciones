#include <bits/stdc++.h>
using namespace std;

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5130

struct premio 
{
  long long v;
  long long x;
  long long a;
  long long d;
  bool operator < (const premio &other) const { return v < other.v; }
  premio(long long a, long long b, long long c, long long e): v(a), x(b), a(c), d(e) {};
};

std::vector<premio> lista1;
std::vector<premio> lista2;
std::vector<premio> lista10;
std::vector<premio> lista20;
long long   vp, xp, ap, dp;
bool v ; //verifica que se encontro una combinatoria correcta

void combinatoria (int ref, int length, int ini, long long v1, long long xp1, long long ap1, long long dp1){

if(v1==vp && xp1==xp && ap1==ap && dp1==dp){
   v= true; 	
}else if(v1<vp && xp1<xp && ap1<ap && dp1<dp){
   
   premio aux (v1, xp1, ap1, dp1);
  
   if(v1 > 0){
   if(ref== 0) lista10.push_back(aux);
   else        lista20.push_back(aux);
   }
   

   for(int i=ini; i<length && !v; i++){

       if(ref==0) combinatoria (ref, length, i+1, v1+lista1[i].v, xp1+lista1[i].x, ap1+lista1[i].a, dp1+lista1[i].d); 
       else       combinatoria (ref, length, i+1, v1+lista2[i].v, xp1+lista2[i].x, ap1+lista2[i].a, dp1+lista2[i].d);
   }
}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long casos, x1, a1, d1, r;
	string n;
	cin>>casos;
	
	while(casos--){
		lista1.clear(); lista2.clear();  v=false;
		lista10.clear(); lista20.clear();
		cin>>xp>>ap>>dp>>r;
		
		vp= xp+ap+dp;
		
		int mitad = r/2;
		for(int i=0; i<r; i++){
		    cin>>n>>x1>>a1>>d1;
		    premio aux (x1+a1+d1, x1, a1, d1);
		    if(i<mitad) lista1.push_back(aux);
		    else        lista2.push_back(aux);
		}
		
		combinatoria(0, lista1.size(), 0, 0, 0, 0, 0);
		combinatoria(1, lista2.size(), 0, 0, 0, 0, 0);
		
	sort(lista10.begin(), lista10.end());
	sort(lista20.begin(), lista20.end());
	if(v){
	cout<<"POSSIBLE\n";	
	}else{
	   int actual = lista20.size()-1;
	   for(int i=0; i<lista10.size() && !v && actual>=0; i++){
	      for(int j=actual; j>=0; j--){
	      	 if(lista10[i].v + lista20[j].v == vp ){
	      	  if((lista10[i].x + lista20[j].x == xp) && (lista10[i].a + lista20[j].a == ap) && (lista10[i].d + lista20[j].d == dp)){
	      	  v=true; break;	
	      	  }
	      	}else if(lista10[i].v + lista20[j].v < vp){
	      	  actual = j; break;
	      	}
	      }
	   }
		if(v) cout<<"POSSIBLE\n";
		else  cout<<"IMPOSSIBLE\n";
	}
	}
	return 0;
}
