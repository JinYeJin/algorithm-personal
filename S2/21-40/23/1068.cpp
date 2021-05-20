/*
[���� 1068] https://www.acmicpc.net/problem/1068
Ʋ�� ���̽� https://www.acmicpc.net/board/view/59793
https://www.acmicpc.net/board/view/51552
*/
#include <stdio.h>
#include <iostream> 
#include <map>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\23\\input\\1068.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, temp, remove, answer = 0;
    int arr[51];
    multimap<int, int> tree;
    vector<pair<int, int>> temp_vec;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> temp;
        temp_vec.push_back({temp, i});
    }

    cin >> remove;

    for(int i = 0; i < N; i++){
        if(temp_vec[i].second == remove || temp_vec[i].first == remove){
            temp_vec.erase(temp_vec.begin() + i);
        }
    }

    for(int i = 0; i < N-1; i++){
        tree.insert(temp_vec[i]);
    }



    queue<int> q;
    q.push(-1);

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        auto found = tree.find(parent);

        // ������尡 ������� ��� ����ó�� ����� ��. ��ĳ��
        if(found == tree.end()) answer++; // Ű ã�Ҵµ� ������ ����
        //else if(found->first == remove) continue; // ����� ���� �н�
        else{ // �������ϴ� ��尡 �ƴϸ�
            // ���� �θ��� �ڽ��� ��� ť�� ����
            for(found; found->first == parent; found++){
                //if(found->second == remove) continue;
                q.push(found->second);
            }
        }
    }

    cout << answer;
    return 0;
}