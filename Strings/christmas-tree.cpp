#include <bits/stdc++.h>
using namespace std;
/*https://www.urionlinejudge.com.br/judge/es/problems/view/1768*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    while (cin >> t) {
        if (t % 2 == 0) {
            t--;
        }

        int contadorestellas = 1;
        int espacios = (t - 1) / 2;
        while (contadorestellas <= t) {
            string c="";
            for (int i = 1; i <= espacios; i++) {
               c+=" ";
            }
            for (int i = 1; i <= contadorestellas; i++) {
              c+="*";
            }
            cout << c+"\n";
            contadorestellas += 2;
            espacios -= 1;
        }
        contadorestellas = 1;
         espacios = (t - 1) / 2;
        while (contadorestellas <= 3) {
            string c="";
            for (int i = 1; i <= espacios; i++) {
               c+=" ";
            }
            for (int i = 1; i <= contadorestellas; i++) {
              c+="*";
            }
            cout << c+"\n";
            contadorestellas += 2;
            espacios -= 1;
        }cout<<"\n";
    }

    return 0;

}