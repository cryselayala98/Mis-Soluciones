#include <bits/stdc++.h>
using namespace std;
#define nodo pair <int, pair <int, int>> //i,j,k
#define mp make_pair
#define f first
#define s second
//https://codeforces.com/group/YjFmW2O15Q/contest/101919/attachments  buscar ejercicio A

int dy[]={-2,0,1,0,-1,0,1,0,-1,0,2,0};
int dx[]={0,1,0,-2,0,2,0,-1,0,1,0,-1,};
int dz[]={3,2,3,2,2,1,2,1,1,3,1,3};
char grid[1005][1005];
int mark[3][1001][1001];
nodo ants[3000010];
int X,Y;
queue <nodo> q;
queue <int> conts;
//1 -> de pie   2-> acostado horizontal   3-> acostado vertical
nodo bfs(int y, int x){
	
	conts.push(1);
	q.push(mp(y,mp(x,1)));
	nodo actual, next;
	int v = 1;
	ants[v-1] = mp(y,mp(x,1));
	mark[0][y][x] = -2 ; //origen
	int act_n ;
	while(!q.empty()){
		actual = q.front(); q.pop();
		act_n = conts.front(); conts.pop();
		int ini = 0;
		if(actual.s.s == 2 ){
			ini =4;	
			if(actual.f <0 || actual.f>=Y || actual.s.f + 1<0 ||actual.s.f + 1>=X) continue;
			if(grid[actual.f][actual.s.f + 1] == '#') continue;
		} 
		else if(actual.s.s == 3){
			ini =8;
			if(actual.f + 1<0 || actual.f + 1>=Y || actual.s.f<0 ||actual.s.f>=X) continue;
			if(grid[actual.f + 1][actual.s.f] == '#') continue;
		}
		else if(grid[actual.f][actual.s.f] == 'E') return actual; //fin
		
		for(int i = 0; i<4; i++){
			next = mp(actual.f+dy[ini+i], mp(actual.s.f+dx[ini+i], dz[ini+i]));
			if(next.f<0 || next.f>=Y || next.s.f<0 ||next.s.f>=X) continue;
			if(grid[next.f][next.s.f] == '#') continue;
			if((next.s.s == 2 && mark[1][next.f][next.s.f] == 0) || (next.s.s == 3 && mark[2][next.f][next.s.f] == 0) || (next.s.s == 1 && mark[0][next.f][next.s.f] == 0)){
					q.push(next);
					v++;
					ants[v-1] = next;
					mark[next.s.s - 1][next.f][next.s.f] = act_n ;
					conts.push(v);
			}
		}
	}
	return mp(-1, mp(-1,-1));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin>>Y>>X;
	int y_ini, x_ini; string a;
	for(int i = 0; i<Y; i++){
		cin>>a;
		for(int j =0; j<X; j++){
			 grid[i][j] = a[j];
			 if(a[j]=='C') y_ini = i, x_ini = j;
		}
	}
	nodo res =	bfs(y_ini, x_ini);
	if(res.s.s!=-1){
		int ant = mark[0][res.f][res.s.f];
		stack <char> rta;
		while(ant!=-2){
			nodo aux = ants[ant-1];
			//validar direccion
			if(aux.f<res.f)rta.push('D');
			else if(aux.f>res.f)rta.push('U');
			else if(aux.s.f<res.s.f)rta.push('R');
			else if(aux.s.f>res.s.f)rta.push('L');
			res = aux;
			ant = mark[res.s.s - 1][res.f][res.s.f];
		}
		cout<<rta.size()<<"\n";
		while(!rta.empty()){
			cout<<rta.top(); rta.pop();
		}
	}else cout<<-1;
	cout<<"\n";
	return 0;
}