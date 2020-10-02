/*
[백준 2225 합분해] https://www.acmicpc.net/problem/2225
참고 https://sihyungyou.github.io/baekjoon-2225/
*/
#include <stdio.h>
#define MOD 1000000000

using namespace std;

int N, K;

int main(){
    FILE *stream =freopen("S2/11/input/2225.txt", "r", stdin);
    if(!stream) perror("freopen");
       int dp[201][201] = { 0, };
    int n, k, i, j;

    scanf("%d %d", &n, &k);

    for (i = 0; i <= n; i++) dp[1][i] = 1;
    for (i = 0; i <= k; i++) dp[i][0] = 1;

    for(i = 2; i <= k; i++) {
        for (j = 1; j <= n; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
        }
    }

    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= n; j++){
            printf("%5d ", dp[i][j]);
        }
        printf("\n");
    }

    printf("%d\n", dp[k][n]); 

    return 0;
}