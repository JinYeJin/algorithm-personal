#include <stdio.h>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int dp[100000];

int main(){
    int T, temp, answer;
    vector<int> numbers;
    
    FILE *stream;
    stream = freopen("SWEA\\16\\1912_input.txt", "r", stdin);
    if(!stream)
        printf("freopen");

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d", &temp);
        numbers.push_back(temp);
    }

    answer = INT_MIN;
    dp[0] = numbers[0];
    answer = numbers[0];

    for(int i = 1; i < numbers.size(); i++){
        dp[i] = max(dp[i-1] + numbers[i], numbers[i]);
        answer = max(answer, dp[i]);
    }
    printf("%d", answer);

    return 0;
}