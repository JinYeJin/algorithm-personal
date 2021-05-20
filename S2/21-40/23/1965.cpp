/*
[백준 1965 상자넣기] acmicpc.net/problem/1965
11053 가장 긴 증가하는 부분수열과 완전히 같은 문제
*/
#include <stdio.h>
#include <iostream> 
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    FILE *stream =freopen("S2\\23\\input\\1965.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, answer = 0;
    int arr[51];
    int arr2[51];
    int dp[1000];

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }



    for(int i = 0; i < N-1; i++){
        cin >> arr2[i];
        int current_dp_value = 0;
        for(int j = i; j >= 0; j--){
            if(arr2[i] > arr2[j]){
                current_dp_value = max(dp[j], current_dp_value);
            }
            dp[i] = current_dp_value + 1;
            answer = max(answer, dp[i]);
        }
    }

    cout << answer;

    return 0;
}