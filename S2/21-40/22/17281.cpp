/*
[백준 17281 야구] acmicpc.net/problem/17281 
*/
#include <stdio.h>
#include <iostream> 

using namespace std;

int main(){
    FILE *stream =freopen("S2\\\\input\\.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    int score[52][9]; 

    cin >> N;

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < 9; j++){
            cin >> score[i][j];
        }
    }

    return 0;
}