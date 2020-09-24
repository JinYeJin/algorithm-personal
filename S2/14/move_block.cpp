#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef struct Coord{
    Coord(int y1, int x1, int y2, int x2, int timer): x1(x1), y1(y1), x2(x2), y2(y2), timer(timer) {}
    int x1, y1, x2, y2, timer;
}Coord;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int N;

bool boundary(Coord cur){
    bool ret1 = cur.x1 >= 0 && cur.x1 < N && cur.y1 >= 0 && cur.y1 < N;
    bool ret2 = cur.x2 >= 0 && cur.x2 < N && cur.y2 >= 0 && cur.y2 < N;
    return ret1 && ret2;
}

bool wall_check(Coord cur, vector<vector<int>> board){
    return !board[cur.y1][cur.x1] && !board[cur.y2][cur.x2];
}

bool visit_check(Coord cur, set<Coord> visited){
    Coord temp_cur = cur;
    temp_cur.timer = -1;
    set<Coord>::iterator iter = visited.find(temp_cur);
    if(iter == visited.end()) return false; // 방문한 적 없음
    else return true;
}

queue<Coord> move(Coord cur){
    queue<Coord> ret;
    
    for(int i = 0; i < 4; i++){
        Coord next = cur;
        next.x1 += dx[i];
        next.x2 += dx[i];
        next.y1 += dy[i];
        next.y2 += dy[i];
        next.timer++;
        if(boundary(next)) ret.push(next);
    }
    // 첫 번째 좌표를 축으로 회전
    for(int i = 0; i < 4; i++){
        Coord next = cur;
        
        int temp_x2 = next.x1 + dx[i];
        int temp_y2 = next.y1 + dy[i];
        // 이전의 좌표는 route에 포함되면 안되므로 검사
        if(temp_x2 != next.x2 && temp_y2 != next.y2){
            next.x2 = temp_x2;
            next.y2 = temp_y2;
            next.timer++;
            if(boundary(next)) ret.push(next);
        }
    }
    // 두 번째 좌표를 축으로 회전
    for(int i = 0; i < 4; i++){
        Coord next = cur;
        
        int temp_x1 = next.x2 + dx[i];
        int temp_y1 = next.y2 + dy[i];
        // 이전의 좌표는 route에 포함되면 안되므로 검사
        if(temp_x1 != next.x1 && temp_y1 != next.y1){
            next.x1 = temp_x1;
            next.y1 = temp_y1;
            next.timer++;
            if(boundary(next)) ret.push(next);
        }
    }

    return ret;
}


int solution(vector<vector<int>> board) {
    int answer = 0;
    
    queue<Coord> route;
    set<Coord> visited;
    N = board.size();
    
    // y1, x1, y2, x2, timer
    route.push(Coord(0, 0, 0, 1, 0));
    
    while(!route.empty()){
        Coord cur = route.front();
        route.pop();
        queue<Coord> temp_route = move(cur);
        
        // N, N 지점에 도달
        if((cur.y1 == N-1 && cur.x1 == N-1) || (cur.y2 == N-1 && cur.x2 == N-1)){
            answer = cur.timer;
            break;
        }
        // 방문 표시
        visited.insert(Coord(cur.y1, cur.x1, cur.y2, cur.x2, -1));
        
        while(!temp_route.empty()){
            Coord temp_cur = temp_route.front();
            temp_route.pop();
            
            // 벽에도 안걸리고 방문한 적이 없으면 경로에 추가
            if(wall_check(temp_cur, board) && !visit_check(temp_cur, visited)) route.push(temp_cur);
        }
        
    }
    
    return answer;
}