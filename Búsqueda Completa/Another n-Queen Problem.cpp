#include <bits/stdc++.h>
using namespace std;

int cont, MAX,n;
bool bad_rows[16][16];
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2136

void search(int row_current, int left_d, int right_d, int col_current){
	if(row_current == MAX){
		cont++; 
		return;
	}
	
	int rows = MAX & (~(row_current | left_d | right_d)); // bits encendidos-> filas que pueden acceder en la sig columna
	while(rows){
		int prox = rows & -rows;
		rows -= prox;
		if(bad_rows[(int)log2(prox)][col_current])continue;
		search(row_current | prox, (left_d | prox)<<1, (right_d | prox)>>1, col_current+1); 
		/* rw | prox -> encendiendo bit de la proxima fila
		   (left_d | prox)<<1 y (right_d | prox)>>1 -> bits encendidos indican las columnas uqe estan ocupadas
																	*/
       
	}

}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int cases = 1; string a;
	while(cin>>n,n){
        memset(bad_rows, 0, sizeof(bad_rows));
        cont = 0;
        MAX = (1<<n) - 1;
        for(int i =0; i<n; i++){
        	cin>>a;
        	for(int j =0; j<n; j++){
        	if(a[j]== '*')bad_rows[i][j] = 1;
        }	
        }
        search(0, 0, 0, 0);
     
      cout<<"Case "<<cases<<": "<<cont<<"\n";
      cases++;
	}

	return 0;
}

