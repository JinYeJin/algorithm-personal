#include <stdio.h>
#include <vector>

using namespace std;


typedef struct _Camera{
    int x, y;
    int kinds;
}Camera;

int N, M; // N: 세로, M: 가로
int office[8][8];
vector<Camera> camera;
// void 

int main(){
    FILE *stream;

    stream = freopen("SWEA\\9_LINE\\15683_input.txt", "r", stdin);

    if(!stream)
        printf("freopen\n");

    scanf("%d %d", &N, &M);

    camera.clear();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &office[i][j]);
            if(office[i][j] != 0 && office[i][j] != 6){
                Camera temp = {i, j, office[i][j]};
                camera.push_back(temp);
            }
        }
    }

    for(int i = 0; i < camera.size(); i++){
        printf("kinds: %d, x: %d, y: %d\n", camera[i].kinds, camera[i].x, camera[i].y);
    }

    vector<Camera>::iterator iter = camera.begin();

    for(iter; iter != camera.end(); iter++){
        
    }

    return 0;
}