#include <stdio.h>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\8\\input\\1477_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, M, L;
    int rest_area[101];

    scanf("%d %d %d", &N, &M, &L);
    for(int i = 0; i < N; i++){
        scanf("%d", &rest_area[i]);
    }
    return 0;
}