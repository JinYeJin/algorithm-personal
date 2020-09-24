#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

    int electric[501];

int main(){
    FILE *stream =freopen("S2\\13\\input\\2565.txt", "r", stdin);
    if(!stream) perror("freopen");
    
    int N, a, b, temp;

    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        scanf("%d %d", &a, &b);

        if(a > b){
            temp = a;
            a = b;
            b = temp;
        }

        for(int i = a; i <= b; i++){
            electric[i] += 1;
        }
    }

    for(int i = 0; i <= 10; i++) printf("%d ", electric[i]);
    return 0;
}