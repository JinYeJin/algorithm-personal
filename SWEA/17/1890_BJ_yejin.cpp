#include <stdio.h>
#include <vector>

using namespace std;

int N, answer;
int new_c, new_r;
int board[100][100];
int dp[100][100];

void bfs(int r, int c){
    if(r == 0 & c == 0) return; 
    // 가로 탐색
    for(int move = 1; move <= c; move++){
        if(board[r][c - move] == move){
            new_c = c - move;
            dp[r][new_c]++;
            bfs(r, new_c);
        }
    }

    
    // 세로 탐색
    for(int move = 1; move <= r; move++){
        if(board[r - move][c] == move){
            new_r = r - move;
            dp[new_r][c]++;
            bfs(new_r, c);
        }
    }

}


int main(){
    FILE *stream = freopen("SWEA\\17\\1890_input.txt", "r", stdin);
    if(!freopen) printf("freopen");


    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &board[i][j]);
        }
    }

    bfs(N-1, N-1);
    printf("%d", &dp[0][0]);
    
    return 0;
}