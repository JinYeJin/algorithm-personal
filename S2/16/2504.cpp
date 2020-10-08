#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\16\\input\\2504.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int answer = 0;
    int multiply = 1;
    bool break_flag = false;

    string input;
    stack<char> bracket;
    map<char, char> pair = {{'(', ')'}, {'[', ']'}};

    cin >> input;

    int i = 1;
    bracket.push(input[0]);

    for(int i = 0; i < input.size(); i++){
        break_flag = true;
        while(!bracket.empty()){
            char cur = bracket.top();
            
            // 스택의 top이랑 현재 input 비교해서 같으면
            if(pair[cur] == input[i]){
                bracket.pop();
                // 같을 때 pop한 다음에 곱해줌 )는 2
                if(input[i] == ')'){
                    
                }
                else if(input[i] == ']'){

                }
            }
            // 다르면 스택에 넣고 끝냄
            else if(input[i] == '(' || input[i] == '['){
                bracket.push(input[i]);
            }
            else{
                break_flag = true;
                break;
            }
        }
        if(break_flag) break;
        answer += multiply;
        bracket.push(input[i]);
    }
    if(!bracket.empty()) cout << answer;
    return 0;
}