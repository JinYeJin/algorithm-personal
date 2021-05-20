#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> pi;

int main(){
    FILE *stream = freopen("S2\\29\\input\\1197.txt", "r", stdin);
    if(!stream) perror("freoepn");

    int V, E;

    cin >> V >> E;

    vector<priority_queue<pi, vector<pi>>> weights(V);
    vector<bool> visited(V, false);

    for(int i = 0; i < E; i++){
        int A, B, C; // 시작 끝 가중치
        cin >> A >> B >> C;

        weights[A].push({C, B}); 
    }

    int start = 0;
    int answer_weight = 0;
    queue<int> path;
    queue<int> answers;
    path.push(start);

    while(answers.size() < V-1){
        int current = path.front();
        path.pop();

        if(weights[current].empty()) continue;

        pi next = weights[current].top();
        int weight = next.first;
        int b = next.second;
        
        if()

        path.push(b);
        answer_weight += weight;
        answers.push(b);
    }

    return 0;
}