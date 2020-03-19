/*
백준 140503 로봇 청소기
2020-03-19
진예진
*/

#include <stdio.h>
#include <queue>

using namespace std;

int test_case;
int T;
int N, M; // N: row, M: column
int r, c, d; // r: row, c: column, d: direction
vector<vector<int>> check_cleaned(50, vector<int>(50, 0));
vector<vector<int>> space(50, vector<int>(50, 0));
vector<pair<int, int>> move_front = {{1, 0}, {0, 1}, // 북, 동
                                      {-1, 0}, {0, -1}}; // 남, 서

int turn_left(int d){
    d = d - 1;
    if(d == -1) d = 3;
    return d;
}

void bfs(int r, int c, int d){
    int x, y;
    int temp_x, temp_y;
    queue<pair<int, int>> q;

    // 시작 지점 큐에 push
    q.push({r, c});
    
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            check_cleaned[y][x] == true;
            d = turn_left(d); // 가던 안가던 왼쪽으로 회전

            temp_y = y + move_front[d].first;
            temp_x = x + move_front[d].second;
            
            // 좌표내이면서 벽이 아닌지 확인
            if
            else if(check_cleaned[temp_y][temp_x] == true) break;
            else if(i == 3){
                move_back[d]
            }
        }

        
    }
}

int main(int agrc, char** args){
    FILE *stream;

    stream = freopen("SWEA\\5\\14503_sample_input.txt", "r", stdin);

    if(!stream)
        perror("freopen");

    scanf("%d", &T);

    for(test_case = 1; test_case <= T; test_case++){
        // vector 초기화
        for(auto &elem : check_cleaned) std::fill(elem.begin(), elem.end(), 0);
        for(auto &elem: space) std::fill(elem.begin(), elem.end(), 0);

        scanf("%d %d", &N, &M);
        scanf("%d %d %d", &r, &c, &d);

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                scanf("%d", &space[i][j]);
            }
        }

        /* 배열 확인
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                printf("%d ", space[i][j]);
            }
            printf("\n");
        }
        */

    }
    return 0;
}