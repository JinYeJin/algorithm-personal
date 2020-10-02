/*
yabmoons.tistory.com/197
namu.wiki/w/%EC%B5%9C%EC%9E%A5%20%EC%A6%9D%EA%B0%80%20%EB%B6%80%EB%B6%84%20%EC%88%98%EC%97%B4
*/
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    // FILE *stream =freopen("S2\\17\\input\\2631.txt", "r", stdin);
    FILE *stream =freopen("S2/17/input/2631.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Max, N;
    int Arr[201], DP[201];

    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> Arr[i];
    }

    Max = 0;
    memset(Arr, 0, sizeof(Arr));
    memset(DP, 0, sizeof(DP));

    for(int i = 1; i <= N; i++){
        DP[i] = 1;
        for (int j = 1; j <= i; j++){
            if (Arr[j] < Arr[i] && DP[i] < DP[j] + 1){
                DP[i] = DP[j] + 1;
            }
        }
        if (Max < DP[i]) Max = DP[i];
    }
 
    cout << N - Max;

    return 0;
}