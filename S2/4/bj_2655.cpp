/*
2020-06-25 진예진
[2655 가장높은탑쌓기] https://www.acmicpc.net/problem/2655
참고 https://inspirit941.tistory.com/entry/Python-%EB%B0%B1%EC%A4%80-2655-%EA%B0%80%EC%9E%A5-%EB%86%92%EC%9D%80-%ED%83%91-%EC%8C%93%EA%B8%B0
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Brick{
    Brick(): index(0), area(0), height(0), weight(0){}
    Brick(int index, int area, int height, int weight): index(area), area(area), height(height), weight(weight){}
    int index, area, height, weight;
}Brick;

bool compare(Brick &a, Brick &b){
    return a.area < b.area;
}

int N;
int dp[101];

int main(){
    FILE *stream = freopen("S2\\4\\input\\2655_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    vector<Brick> bricks(101);
    vector<int> selected;
    bricks.clear();
    selected.clear();

    scanf("%d", &N);

    // 0 번쨰 초기화
    bricks.push_back(Brick(0,0,0,0));

    for(int i = 1; i <= N; i++){
        Brick brick;
        brick.index = i;
        scanf("%d %d %d", &brick.area, &brick.height, &brick.weight);
        bricks.push_back(brick);
    }

    // 너비가 작은 순
    sort(bricks.begin(), bricks.end(), compare);


    for(int i = 1; i <= N; i++) dp[i] = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < i; j++){
            // i 밑의 돌, j 위의 돌
            // 무게가 더 무겁다면 쌓기 가능
            if(bricks[i].weight > bricks[j].weight)
                dp[i] = dp[i] > dp[j] + bricks[j].height ? dp[i] : dp[j] + bricks[j].height;
        }
    }

    int max = -1;
    int index;

    for(int i = 0; i < N; i++) max = dp[i] > max ? dp[i] : max;
    for(int i = 0; i < N; i++)
        if(dp[i] == max) index = i;

    while(index != 0){
        if(max == dp[index]){
            selected.push_back(bricks[index].index);
            max -= bricks[index].height;
        }
        index--;
    }


    printf("%d\n", selected.size());
    for(int i = 0; i < selected.size(); i++) printf("%d\n", selected[i]);

    return 0;
}