#include <bits/stdc++.h>
using namespace std;

/*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=54*/

set <pair<int, int> >w;
int x,y, i,j,ii,jj; string a,b;

int main() {
	cin>>x>>y;
	while(cin>>i>>j>>a>>b){
		bool v = 0;
		for(int k =0; k<b.size(); k++){
			if(b[k] == 'L'){
					    if(a == "N" ) a = "W"; 
				else	if(a == "S" ) a = "E"; 
				else    if(a == "E" ) a = "N";
				else                  a = "S";
			}
			else if(b[k] == 'R'){
						if(a == "N" ) a = "E"; 
				else	if(a == "S" ) a = "W"; 
				else    if(a == "E" ) a = "S";
				else                  a = "N";
			}else{
				 ii = i, jj = j;
				        if(a == "N" ) j++; 
				else	if(a == "S" ) j--;
				else    if(a == "E" ) i++;
				else                  i--;
				if(j<0 || j>y || i<0 || i>x){
					if(w.count(make_pair(ii,jj))) i = ii , j = jj;
					else{
						v = 1;
						w.insert(make_pair(ii,jj));
						break;
					}
				}
			}
		}
		if(v)cout<<ii<<" "<<jj<<" "<<a<<" LOST";
		else cout<<i<<" "<<j<<" "<<a;
		cout<<"\n";
	}
	return 0;
}