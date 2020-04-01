/*
SWEA 8993.하지추측
2020-03-26 진예진
27/31 맞음
문제 링크 https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW6GFM8aLacDFAVX&categoryId=AW6GFM8aLacDFAVX&categoryType=CODE#;return%20false;
*/

#include <stdio.h>
#include <vector>

using namespace std;

int main(void){
    int T;
    long long N;
    vector<long long> loop_check;
    FILE *stream;
/*
    stream = freopen("SWEA\\7\\8993_input.txt", "r", stdin);
    if(!stream)
        printf("freopen");
*/
    scanf("%d" ,&T);

    for(int testcase = 1; testcase <= T; testcase++){
        bool flag = true;
        loop_check.clear();
        scanf("%lld", &N);

        while (N > 1){
            if(!flag) break;
            // printf("%d ",N);
            if(N % 2 == 0){
                N = N / 2;
                //else 부분이 2의 n승이 되면 답이 나올 수 없다
                //2의 n승이면 no 2의 n승이 아니면 yes
            }else{
                N = 3 * N + 3;
            }
            for(auto x:loop_check){
                if(x == N){
                    flag = false;
                    N = 1;
                    break;
                }
            }
            loop_check.push_back(N);
       }
        printf("#%d ", testcase);
        printf(flag? "YES\n": "NO\n");
    }
    return 0;
}