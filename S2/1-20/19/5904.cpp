/*
https://jaimemin.tistory.com/1087
*/
#include <stdio.h>
#include <iostream> 

using namespace std;

int N, idx;

void s(int k){
    if(k == 1){
        if(idx + 1 == N){
            cout << "m";
            exit(0);
        }else if(idx + 2 == N || idx + 3 == N){
            cout << "o";
            exit(0);
        }
        idx += 3;
        return;
    }

    s(k-1);

    if(idx + 1 == N){
        cout << "m";
        exit(0);
    }
    idx++;

    for(int i = 0; i <= N; i++){
        if(idx + 1 == N){
            cout << "o";
            exit(0);
        }
        idx++;
    }
    s(k-1);
}

int main(){
    FILE *stream =freopen("S2\\19\\input\\5904.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    s(30);

    return 0;
}