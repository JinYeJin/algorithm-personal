/*
2020-07-08 진예진
[백준 2156 포도주 시식] https://www.acmicpc.net/problem/2156
참고 https://blog.naver.com/PostView.nhn?blogId=occidere&logNo=220791788953
*/

#include <stdio.h>
#include <algorithm>
#define MAX_WINE 10000

using namespace std;

int main(){
    FILE *stream = freopen("S2/6/input/2156_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N;
    int wine[MAX_WINE] = {0, };
    int dp [MAX_WINE] = {0, };

    scanf("%d", &N);

    for(int i = 1; i <= N; i++) scanf("%d", &wine[i]);

    dp[1] = a[1];
    dp[2] = a[1] + a[2];

    for(int i = 1; i <= N; i++){
        scanf("%d", &wine[i]);
        wine[i] = max(wine[i-1] + wine[i-2], wine[i] + wine[i-1]);
        wine[i] = max(wine[i], wine[i] + wine[i-2]);
    }

    printf("%d", wine[N + 2]);
    return 0;
}