#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\28\\input\\1339.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N;
    int map[52]; // ���ĺ��� ���� ����
    memset(map, -1, sizeof(map));

    cin >> N;

    vector<string> alphabets;
    vector<string> answer_numbers(10, "");



    for(int n = 0; n < N; n++){
        string temp;
        cin >> temp;
        alphabets.push_back(temp);
    }

    sort(alphabets.begin(), alphabets.end());

    int number = 9; // �Ҵ��� ����
    int idx = alphabets[0].size() - 1;

    while(idx >= 0){
        for(int n = 0; n < N; n++){
            int size = alphabets[n].size()-1;
            char ascii = alphabets[n][size-idx];
            int character_idx = (int)ascii - 'A'; 

            // ���ĺ��� �Ҵ�� ���� ������
            if(map[character_idx] == -1){
                map[character_idx] = number;
                number--;
            }

            answer_numbers[n].push_back((char)map[character_idx] + 0x30);

            // ������ �ܾ��̸� idx ����
            if(n == N-1){
                idx--;
            }
            // ������ �ܾ �ƴϰ�, ���� ���ڿ��� index ���� ª���� ���� ���ڿ� �ѹ� �� ����
            else{
                if(alphabets[n+1].size()-1 < idx){
                    n--;
                    idx--;
                }
            }
        }
    }

    int answer = 0;

    for(int n = 0; n < N; n++){
        answer+= stoi(answer_numbers[n]);
    }

    cout << answer;

    return 0;
}