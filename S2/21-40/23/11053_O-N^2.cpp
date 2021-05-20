/*
[���� 11053 ���� �� �����ϴ� �κм���] acmicpc.net/problem/11053
*/
#include <stdio.h>
#include <iostream> 
#include <algorithm>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\23\\input\\11053.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, answer = 0;
    int arr[1000];
    int dp[1000];

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        int current_dp_value = 0;
        for(int j = i; j >= 0; j--){
            if(arr[i] > arr[j]){
                current_dp_value = max(dp[j], current_dp_value);
            }
            dp[i] = current_dp_value + 1;
            answer = max(answer, dp[i]);
        }
    }

    cout << answer;

    return 0;
}