#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\28\\input\\14499.cpp", "r", stdin);
    if(!stream) perror("freopen");

    int N, M, x, y, K;
    int map[22][22];
    int vertical[] = {4, 1, 3};
    int horizon[] = {2, 1, 5, 6};

    cin >> N >> M >> x >> y >> K;

    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){

        }
    }

    return 0;
}