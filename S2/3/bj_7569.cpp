/*
2020-05-17 진예진
[백준 7569] https://www.acmicpc.net/problem/7569
*/

#include <stdio.h>
#include <queue>

using namespace std;

typedef struct Coord{
    Coord(int x, int y, int h): x(x), y(y), h(h) {};
    int x, y, h;
}Coord;

int M, N, H;
int warehouse[100][100][100];
int visited[100][100][100];
queue<Coord> tomatos;

int main(){
    FILE *stream = freopen("S2\\3\\7569_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    // M: 가로(x), N: 세로(y), H: 높이(h) 
    scanf("%d %d %d", &M, &N, &H);

    int num_of_ripe_tomato = 0; 
    int empty = 0;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                scanf("%d", &warehouse[i][j][k]);
                // 1: 익은 토마토, 0: 익지 않은 토마토, -1: 토마토가 들어있지 않음
                if(warehouse[i][j][k] ==  1){
                    num_of_ripe_tomato++;
                    // x, y, h 순서주의
                    tomatos.push(Coord(k, j, i));
                }
                else{
                    empty++;
                }
            }
        }
    }

    // 토마토가 이미 모두 익어있는 경우 예외처리
    if(num_of_ripe_tomato == H * N * M - empty){
        // 0 출력하고 프로그램 종료
        printf("0");
        return 0;
    }
    return 0;
}