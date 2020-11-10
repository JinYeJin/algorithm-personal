/*
*/
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\19\\input\\2531.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, D, K, C;
    vector<int> sushi;
    int temp, num_sushi, max_kinds = 0;
    bool exist_C = false;
    map<int, int> check;
    vector<int>::iterator s_p, e_p;

    // N 초밥의 개수, D 초밥의 종류 수, K 연속으로 먹는 초밥 수, C 쿠폰
    cin >> N >> D >> K >> C;

    for(int i = 0; i < N; i++){
        cin >> temp;
        sushi.push_back(temp);
    }

    // 시작 포인터 초기화
    s_p = sushi.begin();
    check.insert({sushi[1], 1});

    // 처음 K개 초기화
    for(int i = 1; i < K; i++){
        // check 안에 있으면,
        if(check.find(sushi[i]) != check.end())
            check[i]++;
        else check.insert({sushi[i], 1});
    }

    // 마지막 포인터 초기화
    e_p = sushi.end();

    // K 개 이후
    for(int i = K; i < N; i++){
        max_kinds = max_kinds < check.size() ? max_kinds : check.size();

        // 연속된 초밥 안에 C가 없고
        if(check.find(C) == check.end()){
            // 맨 앞이나 끝에 C가 있으면, 종류의 수가 하나 늘어난다.
            ++e_p;
            if(s_p != sushi.begin()){
                --s_p;
                if(*s_p == C) max_kinds++;
                ++s_p; // 위에서 줄인거 복구
            }
            else if(*e_p == C) max_kinds++;
            ++s_p; // 다음 요소
        }// C가 하나라도 있으면 C가 있다고 표시
        else exist_C = true;

        // check 안에 이미 있는 원소라면, value 증가
        if(check.find(*e_p) != check.end()){
            check[*e_p]++;
        }
        else{ // 없는 값이라면 새로 추가해 줌
            check.insert({*e_p, 1});
        }
    }
    cout << max_kinds;
    return 0;
}