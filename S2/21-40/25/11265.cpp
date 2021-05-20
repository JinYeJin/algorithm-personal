/*
[���� 11265 ������ �ʴ� ��Ƽ]
*/

#include <stdio.h>
#include <iostream>
#define INF 987654321

using namespace std;
 
int main(){
    FILE *stream =freopen("S2\\25\\input\\11265.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    int A, B, C;
    int park[501][501];

    cin >> N >> M;
 
    // i == j �밢���� 0���� �ʱ�ȭ. �������� INF
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            park[i][j] = (i == j) ? 0 : INF;
        }
    }

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> park[r][c];
        }
    }
 
    // k�� ���ļ� ���� �� ���� �ٷ� ���� �� ������ Ȯ��
    for(int k = 1; k <= N; k++) {
        for(int r = 1; r <= N; r++) {
            for(int c = 1; c <= N; c++) {
                if(park[r][c] > park[r][k] + park[k][c])
                    park[r][c] = park[r][k] + park[k][c];
            }
        }
    }
 
    for(int i = 0; i < M; i++) {
        // ����, ��, ���� �� �ɸ��� �ð�
        cin >> A >> B >> C;

        if(park[A][B] <= C) cout << "Enjoy other party\n";
        else cout << "Stay here\n";
    }
}