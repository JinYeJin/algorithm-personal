#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
vector<int> relation[100];
int is_visited[100], smaller_child[100], bigger_child[100];
 
int main() {
    int N, M; cin >> N >> M;
    int mid = (N + 1) / 2;
    // 관계 설정 
    for (int i = 0; i < M; ++i) {
        int big, small; cin >> big >> small;
        relation[big].push_back(small);
    }
 
    //각 번호 별로 자기부터 작은 것을 센다
    for (int i = 1; i <= N; ++i) {
        int child_num = 0, start = i;
        memset(is_visited, -1, sizeof(is_visited)); 
 
        // BFS 시작
        queue<int> que;     que.push(start);
        while (!que.empty()) {
            int now_node = que.front(); que.pop();
            int small_node_num = relation[now_node].size();
            for (int j = 0; j < small_node_num; ++j) {
                int child_node = relation[now_node][j]; 
                // 자신보다 큰 노드의 개수를 1 추가하고
                // 처음 BFS를 시작한 노드의 자식수 cnt 를 1 추가
                if (is_visited[child_node] == -1) {
                    bigger_child[child_node]++, child_num++;
                    is_visited[child_node] = 1;
                    que.push(child_node);
                }
            }
        }
        smaller_child[i] = child_num;  //자기보다 작은노드의 수 기록
    }
 
    int ans = 0;
    for (int i = 1; i <= N; ++i)
        if (bigger_child[i] >= mid || smaller_child[i] >= mid) ans++;
 
    cout << ans << endl;
    return 0;
}