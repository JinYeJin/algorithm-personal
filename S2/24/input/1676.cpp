#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\24\\input\\1676.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N;
    int N5 = 0;

    cin >> N; 

    for(int i = 1; i <= N; i++){
        int temp_i = i;
        if(i%5 == 0) N5++;
        if(i%25 == 0) N5++;
        if(i%125 == 0) N5++;
    }

    cout << N5;

    return 0;
}