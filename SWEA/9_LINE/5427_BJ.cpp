/*
백준 5427.불
2020-04-02 진예진
https://www.acmicpc.net/problem/5427
*/

#include <stdio.h>

int main(void){
    FILE *stream;
    int testcase, T;
    int w, h;

    stream = freopen("SWEA\\9_LINE\\5427_input.txt");

    if(!stream)
        printf("freopen\n"); 

    scanf("%d", T);

    for(testcase = 1; testcase <= T; testcase++){
        scanf("%d %d", &w, &h);
        char building[h][w];

        for(int i = 0; i < h; i++){
            for(int j =0; j < w; j++){
                scanf("%c", &building[i][j]);
            }
        }

        
    }

    return 0;
}