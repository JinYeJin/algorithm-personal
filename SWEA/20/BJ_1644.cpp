/*
2020-05-14
소수의 연속합
[백준 1644] https://www.acmicpc.net/problem/1644
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[4000001];
int N;
vector<int> prime;

int main()
{
    int i,j;
    int answer = 0;

    FILE *stream = freopen("SWEA\\20\\1644_input.txt", "r", stdin);
    if(!stream) printf("freopen");

    scanf("%d", &N);

    for (int i = 2; i * i <= N; i++){
        if (arr[i]) continue;
        for (int j = i * i; j <=N; j+=i){
            arr[j] = 1;
        }
    }

    for (int i = 2; i <= N; i++)
        if (arr[i] == 0)
            prime.push_back(i);

    for (i = 0; i < prime.size(); i++){
        int sum = 0;
        for (j = i; j < prime.size(); j++){
            sum += prime[j];
            if (sum > N)
                break;
            if (sum == N){
                answer++;
                break;
            }
        }
    }
    printf("%d", answer);
}
 