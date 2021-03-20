/*
1283 단축키 지정
*/
#include <stdio.h>
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter){
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)){
        answer.push_back(temp);
    }
    return answer;
}

int main(){
    FILE *stream =freopen("S2\\32\\input\\1283.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string temp;
    vector<vector<string>> options(30);
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        // cin >> temp;
        getline(cin, temp);
        // cout << temp << "\n";
        options[i] = split(temp, ' ');
    }

    for(int i = 0; i < N; i++){

    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < options[i].size(); j++){
            cout << options[i][j] << " ";

        }
        cout << "\n";
    }

    return 0;
}