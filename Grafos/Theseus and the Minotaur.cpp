#include <bits/stdc++.h>
using namespace std;

/*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=104

	1.buscar el nodo adyacente a la posicion del minotauro, desde la ubicación actual de theseo.
	2.por cada movimiento que haga el minotauro, theseo se moverá a la posición anterior de este
	  el minotauro no podrá moverse por una caverna con vela encendida, ni hacia la caverna que estuvo anteriormente,porque ahí estará theseo.
	3.cuando se hagan k movimientos, theseo dejará una vela desde su posicion actual y reinicia k.
	4.cuando el minotauro no pueda hacer más movimientos, se dará por ganado y se mostrará la posición donde theseo pudo capturarlo.
*/


vector <int> ady[300];
string directions;
char minotaur, theseus;
int k;

void init(){
	for(int i = 0; i<300; i++){
		ady[i].clear();
	}
}

int dfs(int m, int t, int k_e, bool marked[]){
	
	if(!k)marked[m] = 1;
	else marked[m] = !(++k_e % k); 
	for(int i=0; i<ady[m].size(); i++){
		if(!marked[(int)ady[m][i]] && ady[m][i] != t){ 
			if(marked[m])cout<<(char)m<<" ";
			return dfs(ady[m][i], m, k_e, marked);
		}
	}
		cout<<"/"<<(char)m<<"\n";
	return 0;
}

vector<string> split_char (string str) {
    vector<string> split;
    string aux= "";
    bool z = 0;
    for(int i = 0; i< str.size();i++){
    	if(str[i]==';' || (str[i]==' ' && !z)) {
    		split.push_back(aux);
    		if(str[i]==' ') z = 1;
    		aux="";
    	}

    	else aux+=str[i];
    }
    split.push_back(aux);
    
    return split;
}

int main() {
	bool marked[1000];
	while(getline(cin, directions) && directions != "#"){
		memset(marked, 0,sizeof(marked));
		init();
		vector <string> dir =  split_char(directions);
		for(int i = 0; i< dir.size()-1; i++){
			char a = dir[i][0];
			
			for(int j = 2; j<dir[i].size(); j++){
				if(dir[i][j] == ':' || dir[i][j] == '.') break;
				ady[(int)a].push_back(dir[i][j]);
			}
		}
		
		minotaur = dir[dir.size()-1][0];
		theseus = dir[dir.size()-1][2];
		k = 0;
		int i = 4;
		while(i<dir[dir.size()-1].size() && dir[dir.size()-1][i]!=' ')k = k * 10 + (dir[dir.size()-1][i++] - '0');
		dfs((int)minotaur, (int)theseus, 0, marked);
	}
	return 0;
}