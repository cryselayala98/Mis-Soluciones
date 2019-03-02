
#include <bits/stdc++.h>
using namespace std;

//https://www.urionlinejudge.com.br/judge/es/problems/view/1162

static int men(int a [], int ini, int fin) {
    int men = a[ini];
    int posmen = ini;
    for (int i = ini; i <= fin; i++) {
        if (a[i] < men) {
            men = a[i];
            posmen = i;
        }
    }
    return posmen;
}

int main() { 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int casos;
    cin>>casos;
    while (casos-- > 0) {
        int l;
        cin>>l;
        int trenes[l];
        int i = 0;
        while (i < l) {
            int k;
            cin>> k;
            trenes[i] = k;
            i++;
        }
        int contador = 0;
        for (int s = 0; s < l; s++) {
            int posmen = men(trenes, s, l - 1);

            if (posmen>s) {
                contador += (posmen - s);
                int o=s;
                for (int y = posmen ; y >= s; y--) {
                    int aux = trenes[y];
                    trenes[y] = trenes[y-1];
                    trenes[y-1] = aux;
                }
            }
        }
        cout << "Optimal train swapping takes " << contador << " swaps.\n";
    }



    return 0;
}









