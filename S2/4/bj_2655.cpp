/*
2020-06-25 진예진
[2655 가장높은탑쌓기] https://www.acmicpc.net/problem/2655
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Brick{
    Brick(): area(0), height(0), weight(0){}
    Brick(int area, int height, int weight): area(area), height(height), weight(weight){}
    int area, height, weight;
}Brick;

bool compare(Brick &a, Brick &b){
    if(a.area == b.area){
        return a.height > b.weight;
    }
    else return a.area > b.area;
}

int N;
int dp[101][101];

bool condition_check(Brick lower, Brick upper){
    if(lower.area < upper.area) return false; // 아랫돌이 면적이 더 작으면
    else if(lower.weight < upper.weight) return false; // 아랫돌이 더 가벼우면
    else return true;
}

int main(){
    FILE *stream = freopen("S2\\4\\input\\2655_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    vector<Brick> bricks(101);
    vector<int> selected;
    bricks.clear();
    selected.clear();

    scanf("%d", &N);

    // 0 번쨰 초기화
    bricks.push_back(Brick(0,0,0));

    for(int i = 0; i < N; i++){
        Brick brick;
        scanf("%d %d %d", &brick.area, &brick.height, &brick.weight);
        bricks.push_back(brick);
    }

    // 1. 너비가 넓은 것, 무게가 무거운 것 순
    sort(bricks.begin(), bricks.end(), compare);


    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            // 같은경우 바로패스
            if(i == j){
                dp[i][i] = -1;
                continue;
            }

            Brick *lower = &bricks[i];
            Brick *upper = &bricks[j];

            // 쌓을 수 있는 조건 만족 못하면 -1
            if(condition_check(*lower, *upper) == false){
                dp[i][j] = -1; 
                continue;
            }

            if(i == 1 || j == 1){
                dp[i][j] = lower -> height + upper -> height;
            }
            else{
                int temp;
                if(dp[i][j-1] > dp[i-1][j]){
                    temp = dp[i][j-1];
                    if(dp[i][j-1] != -1) selected.push_back(i);
                }
                else{
                    temp = dp[i-1][j];
                    if(dp[i-1][j] != -1) selected.push_back(i-1);
                }
                // dp[i][j] = dp[i][j] + (dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j]);
                dp[i][j] = temp;
            }
            printf("%d", dp[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    printf("%d\n", selected.size());
    for(int i = 0; i < selected.size(); i++) printf("%d\n", selected[i]);

    return 0;
}