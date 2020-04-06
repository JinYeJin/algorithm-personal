#include <stdio.h>
#include <vector>

using namespace std;


typedef struct _Camera{
    int x, y;
    int kinds;
}Camera;

typedef struct
{
        int x, y;
}Dir;

Dir move_dir[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; //right, down, left, up 
 
// dir_map[kinds][direction]
int dir_map[4][4][2] = {{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}, // move_dir에 해당 값을 
                        {{1, 0}, {0, 1}},
                        {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}}, // right_up, right_down, left_down, left_up
                        {{1, 1}}};

int N, M; // N: 세로, M: 가로
vector<Camera> cameras;



void check(int office[][8]){

}

int trans(int office[][8], Camera camera, int direction){
    int x = camera.x;
    int y = camera.y;
    int kinds = camera.kinds - 1;

    while(true){
        x = x + dir_map[kinds][direction][0];
        y = y + dir_map[kinds][direction][1];

        if(x > M || x < 0 || y > N || y < 0) break;
        else if(office[y][x] == 6) break;
        else if(office[y][x] == 0){
            office[y][x] = -1; // 감시하는 영역
        } 
    }
}

void recur(int office[][8], int camera_idx){
    if(camera_idx > cameras.size()) return;
    else{
        recur(office, camera_idx + 1);
        switch(cameras[camera_idx].kinds){
            case 1: // direction 0: 오른쪽, 1: 아래
                for(int i = 0; i < 4; i++){
                    
                }
            case 2:
            case 3:
            case 4:
        }
    }
} 

int main(){
    FILE *stream;

    stream = freopen("SWEA\\9_LINE\\15683_input.txt", "r", stdin);

    if(!stream)
        printf("freopen\n");

    scanf("%d %d", &N, &M);

    cameras.clear();
    int office[8][8];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &office[i][j]);
            if(office[i][j] != 0 && office[i][j] != 6){
                Camera temp = {i, j, office[i][j]};
                cameras.push_back(temp);
            }
        }
    }

    for(int i = 0; i < cameras.size(); i++){
        printf("kinds: %d, x: %d, y: %d\n", cameras[i].kinds, cameras[i].x, cameras[i].y);
    }

    // vector<Camera>::iterator iter = camera.begin();

    // for(iter; iter != camera.end(); iter++){
        
    // }



    return 0;
}