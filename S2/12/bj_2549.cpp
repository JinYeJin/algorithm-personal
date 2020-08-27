/*
*/
#include <stdio.h>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\\\input\\.txt", "r", stdin);
    if(!stream) perror("freopen");

    int rubik[4][4];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%d", &rubik[i][j]);
        }
    }

    
    return 0;
}