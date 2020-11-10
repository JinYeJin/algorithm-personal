/*
*/
#include <stdio.h>
#include <iostream> 
#include <queue>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\20\\input\\17780.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int chess[12][12]; // 체스판 배열
    vector<vector<queue<int>>> pieces(12, vector<queue<int>>(12, queue<int>())); // 체스말 배열
    int N, K;
    int r, c, d;

    cin >> N >> K;

    for(r = 0; r < N; r++){
        // pieces.push_back(vector<queue<int>>);
        for(c = 0; c < N; c++){
            cin >> chess[r][c];
        }
    }

    for(int n = 0; n < K; n++){
        cin >> r >> c >> d;
        pieces[r][c].push(d);
    }

    return 0;
}