#include <vector>
#include <stdio.h>

using namespace std;

vector<vector<int>> bricks(15, vector<int>(12, 0));

int dfs(int start_p, int end_p){
    return 0;
}

int main(){
    int test_case;
	int T;
    // N: 떨어지는 구슬의 수, W: 블럭의 너비, H: 블럭의 높이
    int N, W, H;
    FILE *stream;

    stream = freopen("SWEA\\2\\sample_input.txt", "r", stdin);
    
    if(!stream)
        perror("freopen");

    scanf("%d", &T);

    for(test_case = 1; test_case <= T; test_case++){
        scanf("%d %d %d", &N, &W, &H);

        for(int r = 0; r < H; r++){
            for(int c = 0; c < W; c++){
                scanf("%d", &bricks[r][c]);
            }
        }

        for(int r = 0; r < H; r++){
            for(int c = 0; c < W; c++){
                printf("%d ", bricks[r][c]);
            }
            printf("\n");
        }

    }
    return 0;
}