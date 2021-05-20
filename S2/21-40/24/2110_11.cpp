#include <stdio.h>
#include <algorithm>

int houses[200000];

int parametric(int start, int end) {
    int mid, tempMid;
    
    while(start <= end) {
        mid = tempMid;
        tempMid = (start+end) / 2;

        if(24/tempMid > 7) {
            start = tempMid + 1;
        }
        else if(24/tempMid < 7) {
            end = tempMid - 1;
        }
        else {
            break;
        }
    }
    return mid;
}

int main(){
    FILE *stream =freopen("S2\\\\input\\.txt", "r", stdin);
    if(!stream) perror("freopen");
    int N, C;

    scanf("%d", &N, &C);

    for(int n = 0; n < N; n++){
        scanf("%d", &houses[n]);
    }

    sort(houses, houses + N);

    

    return 0;
}