/*
14226 이모티콘
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\31\\input\\14226.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int S;
    int dp[1001];

    // memset(dp, 0, sizeof(dp));

    cin >> S;

    for(int i = 0; i <=S; i++)
        dp[i] = 987654321;

    dp[1] = 1; 
    dp[2] = 3;


    for(int i = 2; i <= S; i++){
        for(int n = 2; n <  i; n++){
            if(i%n == 0) dp[i] = min(dp[i], dp[i/n]+2);
        }
    }

    for(int i = 0; i <= S; i++)
        cout << dp[i] << " ";

    cout << "\n";

    for(int i = S; i >=1; i--){
        dp[i] = min(dp[i], dp[i+1] + 1);
    }

    for(int i = 0; i <= S; i++)
        cout << dp[i] << " ";
    cout << dp[S] << " ";

    return 0;
}