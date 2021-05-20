/*
[백준 11053 가장 긴 증가하는 부분수열] https://www.acmicpc.net/problem/11053
*/
#include <stdio.h>
#include <iostream> 
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\23\\input\\11053.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, len = 0;
    int dp[1000];

    memset(dp, 0, sizeof(dp));

    cin >> N;

    for(int i = 1; i <= N; i++){
        int current_dp_value;
        cin >> current_dp_value;

        auto position = lower_bound(dp + 1, dp + len + 1, current_dp_value);
        *position = current_dp_value;
        //cout << i << " position " << position << " last " << dp + len + 1 << "\n";
        if(position == dp + len + 1){
            len++;
        } 
    }

    cout << len;
    return 0;
}