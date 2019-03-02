//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503
#include <bits/stdc++.h>
#define MAX_COINS 102
#define MAX(A,B) ( (A >= B)? (A) : (B) )

int n, m;
int coin[MAX_COINS];
int max;
int sum;
int max_sum[MAX_COINS][MAX_COINS * 500];

int knapsack(int total_coins, int weigth_limit) {
    int i;
    int cur_limit;
    for (i = 0; i <= weigth_limit; i++)
        max_sum[0][i] = 0;

    for (i = 1; i <= total_coins; i++){
        for (cur_limit = 0; cur_limit <= weigth_limit; cur_limit++) {
            if (coin[i] <= cur_limit)
                max_sum[i][cur_limit] = MAX(max_sum[i - 1][cur_limit], max_sum[i - 1][cur_limit - coin[i]] + coin[i]);
            else
                max_sum[i][cur_limit] = max_sum[i - 1][cur_limit];
        }}
    return max_sum[total_coins][weigth_limit];
}

int main() {
    int i, j, diferencia;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        sum = 0;
        for (j = 1; j <= m; j++) {
            scanf("%d", &coin[j]);
            sum += coin[j];
        }
        diferencia = knapsack(m, sum / 2);
        diferencia = sum - diferencia * 2;
        printf("%d\n", diferencia);
    }
    return 0;
}


