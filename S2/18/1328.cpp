/*
[1328 °íÃþ ºôµù] https://www.acmicpc.net/problem/1328
https://ksj14.tistory.com/entry/BackJoon1328-%EA%B3%A0%EC%B8%B5-%EB%B9%8C%EB%94%A9
*/
#include <stdio.h>
#define MOD 1000000007

using namespace std;

int n, l, r;
int dp[101][101][101];

int main(){
    FILE *stream =freopen("S2\\\\input\\.txt", "r", stdin);
    if(!stream) perror("freopen");

    int i, j, k;
    long long int temp;
 
    scanf("%d %d %d", &n, &l, &r);
 
    dp[1][1][1] = 1;
    dp[2][2][1] = dp[2][1][2] = 1;
 
    for (i = 3; i <= n; i++) {
        dp[i][i][1] = dp[i][1][i] = 1;
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                temp = dp[i - 1][j][k];
                temp = (temp * (i - 2)) % MOD;
                temp = (temp + dp[i - 1][j - 1][k]) % MOD;
                temp = (temp + dp[i - 1][j][k - 1]) % MOD;
 
                dp[i][j][k] = temp;
            }
        }
    }
 
    printf("%d\n", dp[n][l][r]);
    return 0;
}