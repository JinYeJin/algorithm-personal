/*
2146 �ٸ� �����
��� 3
*/
#include <stdio.h>
#include <iostream> 
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef struct Coord{
    Coord(int x, int y, int b): x(x), y(y), len_bridge(b) {}
    int x, y, len_bridge;
}Coord;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int map[102][102];
bool visited[102][102];
bool started[102][102];


void check_island(vector<Coord> &starting_points, Coord start, int island_order){
    queue<Coord> path;
    path.push(start);
    visited[start.y][start.x] = true;

    while(!path.empty()){
        Coord cur = path.front();
        path.pop();

        for(int d = 0; d < 4; d ++){
            Coord next = {cur.x + dx[d], cur.y + dy[d], 0};

            // �ٿ���� üũ
            if(map[next.y][next.x] != -1){
                // �ٴٿ� �´�� �ִ� ����(���� �����ڸ� �Ǻ�)
                if(map[next.y][next.x] == 0){
                    if(!started[cur.y][cur.x]){
                        starting_points.push_back(cur);
                        // ���� �������� ��ϵ� ���� �ִ°� Ȯ��
                        started[cur.y][cur.x] = true; 
                    }
                }
                if(!visited[next.y][next.x]){
                    // ���� ������ ���� �����̸�
                    if(map[next.y][next.x] == 1){
                        map[next.y][next.x] = island_order;
                        path.push(next);
                    }
                    visited[next.y][next.x] = true;
                }
            }
        }
    }
    return;
}


int build_bridge(Coord start){
    queue<Coord> path;
    path.push(start);

    while(!path.empty()){
        Coord cur = path.front();
        path.pop();

        for(int d = 0; d < 4; d++){
            Coord next = {cur.x + dx[d], cur.y + dy[d], cur.len_bridge + 1};

            // �ٿ���� üũ
            if(map[next.y][next.x] != -1){
                // ���� ������ ���� �ٴ��̸� �ٸ��� �Ǽ�
                if(map[next.y][next.x] == 0){
                    path.push(next);
                    visited[next.y][next.x] = true;
                }// ���� ������ ���� �ٸ� ������ ��
                else if(map[next.y][next.x] != map[start.y][start.x]){
                    return cur.len_bridge;
                }
            }

        }
    }
    return 98765432;
}

int main(){
    FILE *stream = freopen("S2\\32\\input\\2146.txt", "r", stdin);
    if(!stream) perror("freopen");
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int N = 1;
    int island_order = 1;
    vector<Coord> starting_points;
    queue<Coord> path;

    scanf("%d", &N);

    // �� �ʱ�ȭ
    for(int r = 0; r <= N+1; r++){
        for(int c = 0; c <= N+1; c++){
            // �ٿ���� 
            if(r == 0 || r == N+1 || c == 0 ||c == N+1)
                map[r][c] = -1;
            else scanf("%d", &map[r][c]);
        }
    }

    //starting_points[island_order].push_back(Coord(c, r));

    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            if(!visited[r][c]){
                if(map[r][c] == 1){ // ������ ��� �󺧸�
                    Coord start = Coord(c, r, 0);
                    map[r][c] = island_order;
                    // bfs�� ��ȸ�ϸ鼭 �󺧸�
                    check_island(starting_points, start, island_order);
                    island_order++;
                }
            }
        }
    }

    memset(visited, false, sizeof(visited));

    int answer = 987654321;

    for(int i = 0; i < starting_points.size(); i++){
        Coord start = starting_points[i];
        int len_bridge = build_bridge(start);
        answer = answer > len_bridge ? len_bridge : answer;
    }

    
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            printf("%d ", map[r][c]);
        }
        printf("\n");
    }

    printf("%d", answer);
    return 0;
}