/*
[백준 1197 최소스패닝트리] https://www.acmicpc.net/problem/1197
https://huiung.tistory.com/76
*/
#include <iostream>
#include <vector>
#include <queue>
#define P pair<int, int>

using namespace std;

int visited[10001];
vector<P> edge[10001];
/* 프링 알고리즘
   우선순위 큐를 이용하여 방문할 수 있는 정점중 가중치가 가장 낮은 정점으로 이동 
   프림은 ElogV 의 시간복잡도 
*/ 
int prim() {
	long long ans = 0;
	priority_queue<P, vector<P> , greater<P>>pq; // first는 가중치 second 는 정점 minheap 
	pq.push(P(0, 1)); //1번 정점부터 시작       // 가중치가 가장작은것이 top으로 가게된다! 
	
	while(!pq.empty()) {
		P cur = pq.top();
		pq.pop();
		
		if(visited[cur.second]) //방문 정점 표시 
			continue;
		visited[cur.second] = 1; 
		
		ans += cur.first;
		
		for (int i = 0; i < edge[cur.second].size(); i++) { //현재 정점에서 이동 할 수 있는 방문하지 않은 정점 푸쉬 
			if (!visited[edge[cur.second][i].second]) {
				pq.push(edge[cur.second][i]);
			}
		}
	}
 	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int V, E;
	cin >> V >> E;
	
	for(int i = 0; i < E; i++) {
		int A,B,C;
		cin >> A >> B >> C;
		edge[A].push_back(P(C, B));
		edge[B].push_back(P(C, A));
	}
	
	long long result = prim();
	cout<< result;
	return 0;
}

/*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

typedef struct Node{
    Node(int dst, int weight): dst(dst), weight(weight) {}
    int dst, weight;
}Node;

bool visited[10001] = { false, };
vector<vector<Node>> graph(10001);

int main(){
    FILE *stream =freopen("S2\\13\\input\\1197.txt", "r", stdin);
    if(!stream) perror("freopen");

    int num_node, num_edge;
    int a, b, w;
    int min_w;
    long long total_weight = 0;

    scanf("%d %d", &num_node, &num_edge);


    for(int i = 0; i < num_edge; i++){
        scanf("%d %d %d", &a, &b, &w);
        // 양방향 연결
        graph[a].push_back(Node(b, w));
        graph[b].push_back(Node(a, w));
    }

    int index = 1;
    int b_index, next_index;
    int current_w;
    int node_cnt = 0;

    while(node_cnt < num_node){
        if(visited[index] == true){
            index = (index + 1) % num_node;
        }
        else{
            visited[index] = true;
            min_w = INT_MAX;
            for(int j = 0; j < graph[index].size(); j++){
                current_w = graph[index][j].weight;
                b_index = graph[index][j].dst;

                if(!visited[b_index] && current_w < min_w){
                    min_w = current_w;
                    next_index = b_index;
                }
            }
            // 찾은 노드의 가중치를 더해주고 다음 탐색 노드를 업데이트 해줌, 찾은 노드개수 증가
            if(min_w != INT_MAX) total_weight += min_w;
            index = next_index;
            node_cnt++;
        }
    }

    printf("%d", total_weight);

    return 0;
}
*/