#include <bits/stdc++.h>
using namespace std;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1061*/

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string dia1, dia2, dospuntos;

    int numdia1, hora1, min1, seg1;
    int numdia2, hora2, min2, seg2;
    int numdia3, hora3, min3, seg3;


    cin >> dia1 >> numdia1;
    getline(cin, dospuntos);
    cin >>  hora1 >> dospuntos >> min1 >> dospuntos>> seg1;
    getline(cin, dospuntos);
    cin >> dia2 >>  numdia2;
    getline(cin, dospuntos);
    cin >>  hora2 >> dospuntos >> min2 >> dospuntos>> seg2;

    numdia3 = numdia2 - numdia1;

    if (hora2 - hora1 < 0) {
        hora3 = 24 - (hora1 - hora2);
        numdia3--;
    } else {
        hora3 = hora2 - hora1;
    }

    if (min2 - min1 < 0) {
        min3 = 60 - (min1 - min2);
        hora3--;
    } else {
        min3 = min2 - min1;
    }

    if (seg2 - seg1 < 0) {
        seg3 = 60 - (seg1 - seg2);
        min3--;
    } else {
        seg3 = seg2 - seg1;
    }

    
    cout<< numdia3<<" dia(s)\n"<<hora3<<" hora(s)\n"<<min3<<" minuto(s)\n"<<seg3<<" segundo(s)"<<endl;
    return 0;
}