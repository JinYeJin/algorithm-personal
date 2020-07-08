/*
2020-07-08 진예진
[백준 2156 포도주 시식] https://www.acmicpc.net/problem/2156
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

    scanf("%d", &N);

    wine[0] = wine[1] = 0;
    
    for(int i = 2; i <= N + 2; i++){
        scanf("%d", &wine[i]);
        wine[i] = max(wine[i-1] + wine[i-2], wine[i] + wine[i-1]);
        wine[i] = max(wine[i], wine[i] + wine[i-2]);
    }

    printf("%d", wine[N + 2]);
    return 0;
}