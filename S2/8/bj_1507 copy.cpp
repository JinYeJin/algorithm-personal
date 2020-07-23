#include <cstdio>
using namespace std;

int dist[21][21];
bool notUse[21][21];

int main(){
    FILE *stream =freopen("S2\\8\\input\\1507_input.txt", "r", stdin);
    if(!stream) perror("freopen");
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            scanf("%d", &dist[i][j]);
        }
    }

    for (int k = 1; k <= N; k++){
        for (int i = 1; i <= N; i++){
            if (i == k) continue;
            for (int j = 1; j <= N; j++){
                if (i == j) continue;
                if (k == j) continue;

                printf("%d %d ", dist[i][k] + dist[k][j], dist[i][j]);
                if (dist[i][j] == dist[i][k] + dist[k][j]){
                    notUse[i][j] = true;
                    printf("t");
                }

                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    printf("-1\n");
                    return 0;
                }
                printf("\n");
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (notUse[i][j]) continue;
            ans += dist[i][j];
        }
    }

    printf("%d\n", ans / 2);
    return 0;
}