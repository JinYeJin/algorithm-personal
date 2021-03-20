/*
15991 MooTube
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int main(){
    FILE *stream =freopen("S2\\33\\input\\15591.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;

    cin >> N >> Q;

    int dist[5001];
    // priority_queue<Node, vector<Node>, greater<int>> pq;
    priority_queue<pair<int, int>> pq;
    vector<pair<int, int>> usado[N+1];
    // memset(usado, 0, sizeof(usado));

    for(int i = 1; i < N; i++){
        int p, q, r;

        cin >> p >> q >> r;

        // usado[p][q] = r;
        usado[p].push_back({q, r});
        usado[q].push_back({p, r});
    }

    for(int q = 0; q < Q; q++){
        int K, V;
        cin >> K >> V;

        for(int n = 0; n <= N; n++){
            dist[n] = INF;
        }

        dist[V] = 0;
        pq.push(make_pair(0, V)); // V는 시작노드

        while(!pq .empty()){

            auto current = pq.top();
            pq.pop();
            int similarity  = current.first;
            int v = current.second;

            for(int i = 0; i < usado[v].size(); i++){
                int next = usado[v][i].second;
                int next_similar = usado[v][i].first;
                if(dist[next] > similarity + next_similar){
                    dist[next] = similarity + next_similar;
                    pq.push(make_pair(dist[next], next));
                }
            }
        }

        cout << q << "\n";
        for(int i = 1; i <= N; i++){
            if(dist[i] == INF) cout << "INF ";
            else cout << dist[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}