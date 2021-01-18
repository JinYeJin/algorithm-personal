/*
1493 박스 채우기
https://devbelly.tistory.com/63
*/
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int length, width, hegiht, N, ans;
pair<int, int> cube[21];
bool check = true;

void recur(int l, int w, int h, int idx) {
    if (idx == -1) {
        if ((long long)l * w * h > 0) check = false;
        return;
    }
    auto& [len, cnt] = cube[idx];
    if (len > l || len > w || len > h || cnt == 0) {
        recur(l, w, h, idx - 1);
        return;
    }
    --cnt;++ans;
    recur(l - len, w, h, idx);
    recur(len, len, h - len, idx);
    recur(len, w - len, h, idx);
 
}

int main() {
    FILE *stream = freopen("S2//28//input//1493.txt", "r", stdin);
    if(!stream) perror("freopen");
    cin >> length >> width >> hegiht >> N;

    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;

        cube[i].first = pow(2, a);
        cube[i].second = b;
    }
 
    recur(length, width, hegiht, N - 1);
 
    if (!check) cout << -1;
    else cout << ans;
 
    return 0;
}