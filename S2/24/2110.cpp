#include <stdio.h>
#include <algorithm>

using namespace std;

int houses[200000];
int N, C;

int parametric(int start, int end){
    int mid, temp_mid, num_houses;
    int cmp;
    
    while(start <= end){
        mid = (start+end) / 2;
        num_houses = 1;
        cmp = houses[0];

        for(int i = 0; i < N; i++){
            if((houses[i] - cmp) >= mid){
                num_houses++;
                cmp = houses[i];
            }
        }

        // 찾은 값이 원래 답보다 크면 공유기 설치 거리를 늘림 
        if(num_houses >= C){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return mid;
}


int main(){
    FILE *stream =freopen("S2\\24\\input\\2110.txt", "r", stdin);
    if(!stream) perror("freopen");

    scanf("%d", &N, &C);

    for(int n = 0; n < N; n++){
        scanf("%d", &houses[n]);
    }

    sort(houses, houses + N);
    
    printf("%d", parametric(1, houses[N-1] - houses[0]));

    return 0;
}