#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

typedef struct Coord{
    Coord(int x, int y): x(x), y(y) {}
    int x, y;
    bool broken; // 벽을 부셨냐 아니냐?
}Coord;

int main(){
    FILE *stream = freopen("S2\\24\\input\\2234.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, M; // N: 열, M: 행
    int catsle[52][52];
    int visited[52][52];
    queue<Coord> path;

    scanf("%d %d", &N, &M);
    memset(catsle, 0, sizeof(catsle));
    memset(visited, 0, sizeof(visited));

    for(int r = 1; r < M; r++){
        for(int c = 1; c < N; c++){
            scanf("%d", catsle[r][c]);
        }
    }

    for(int r = 1; r < M; r++){
        for(int c = 1; c <N; c++){
            if(!visited[r][c]){
                path.push(Coord(r, c));
                while(!path.empty()){
                    Coord cur = path.front();
                    path.pop();

                    for(int d = 0; d < 4; d++){
                        
                    }
                }
            }
        }
    }

    return 0;
}