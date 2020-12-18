#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;


typedef struct Coord{
    Coord(int y, int x): x(x), y(y) {}
    int x, y;
}Coord;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    FILE *stream =freopen("S2\\24\\input\\2667.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N;
    int map[27][27];
    queue<Coord> q;
    priority_queue<int, vector<int>, greater<int>> answer; // ê°? ê·¸ë£¹?˜ ì§‘ì˜ ê°œìˆ˜

    memset(map, 0, sizeof(map));
    cin >> N;

    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            // cin >> map[r][c];
            scanf("%1d", &map[r][c]);
        }
    }

    int group_idx = 2;

    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            if(map[r][c] == 1){ // ì§‘ì´ ?žˆ?œ¼ë©?
                q.push(Coord{r, c});
                map[r][c] = group_idx;
                int num_of_house = 0;
                while(!q.empty()){
                    Coord cur = q.front();
                    q.pop();
                    num_of_house++;

                    for(int d = 0; d < 4; d++){
                        Coord ncur = {cur.y + dy[d], cur.x + dx[d]};
                        if(map[ncur.y][ncur.x] == 1){ // ê°?? ¤?Š” ê³³ì— ì§‘ì´ ?žˆ?œ¼ë©?
                            q.push(Coord(ncur));
                            map[ncur.y][ncur.x] = group_idx;
                        }
                    }
                }

                group_idx++;
                answer.push(num_of_house);

            }
        }
    }

    printf("%d\n", answer.size());

    while(!answer.empty()){
        // cout << answer.top() << "\n";
        printf("%d\n", answer.top());
        answer.pop();
    }
>>>>>>> d8b0bf2d366c32213d1aeaba21c8f5f9318dfe02

    return 0;
}