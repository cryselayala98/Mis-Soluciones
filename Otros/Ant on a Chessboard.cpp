#include <bits/stdc++.h>
using namespace std;

//https://vjudge.net/problem/UVA-10161

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int i;
	while(cin>>i && i){
		
		long long v = 1;
		int p=1; int c = 0;
		while(i-v>=0){
			c++;
			i-=v;
			v= 8*p;
			p+=1;
		}
		
		int y = (2*c)-1; int x = 1;  //iniciales

		int d = y;
		//paso 1
		if(i-1 <0)goto final;
		i--;
		y++;
		//paso 2
		if(i-d < 0){
			x+=i;
			goto final;
		}
		i-=d; x+=d;
		//paso 3
		if(i-d < 0){
			
			y-=i;
			goto final;
		}
		i-=d; y-=d;
		//paso 4;
		if(i-1 <0)goto final;
		i--;
		x++;
		//paso 5
		if(i-(d+1) < 0){
			y+=i;
			goto final;
		}
		i-=d+1; y+=d+1;
		//paso 6
		if(i-(d+1) < 0){
			x-=i;
			goto final;
		}
		i-=d+1; x-=d+1;
		
		final :cout<<x<<" "<<y<<endl;
	}
	return 0;
}