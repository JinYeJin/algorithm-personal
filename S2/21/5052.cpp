/*
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){
    FILE *stream =freopen("S2\\21\\input\\5052.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    bool exit_flag;
    vector<string> numbers;

    cin >> T;
    cin >> N;

    for(int t = 0; t < T; t++){
        numbers.clear();
        // 번호 입력
        for(int n = 0; n < N; n++){
            string temp;
            cin >> temp;
            numbers.push_back(temp);
        }

        exit_flag = false;

        for(int n = 0; n < N-1; n++){
            for(int i = 0; i < 10; i++){
                string *str1 = &numbers[n];
                string *str2 = &numbers[n+1];
                // str1이 str2의 prefix인 경우
                // str2가 str1의 prefix인 경우 => 일관성이 없다.
                if(i >= str1->size() || i >= str2->size()){
                    cout << "NO\n";
                    exit_flag = true;
                }

                // 다른 경우엔 다음 단어로 넘어감
                if(str1[i] != str2[i]) break;
            }

            if(exit_flag) break;
        }

        if(!exit_flag) cout << "YES\n";
    }
    return 0;
}