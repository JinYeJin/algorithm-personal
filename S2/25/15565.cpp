/*
[백준 15565 귀여운 라이언] https://www.acmicpc.net/problem/15565
*/
#include <stdio.h>
#include <iostream> 

using namespace std;

int toys[1000001];

int main(){
    FILE *stream =freopen("S2\\\\input\\.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;

    cin >> N >> K;

    int left, right;
    int lion = 0;
    int temp_length = 0;
    int min_legth = 987654321;

    left = right = 1;

    for(int i = 0; i < N; i++){
        cin >> toys[i];
        // 라이언이 1
        if(toys[i] == 1) lion++;
        eles{
            right
        }
        if(lion >= K){
           temp_length = right - left;
        }
    }

    return 0;
}