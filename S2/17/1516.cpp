/*
*/
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\17\\input\\1516.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, temp;
    int time_to_build[502];
    vector<vector<int>> info(502);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> time_to_build[i];
        cin >> temp;
        while(temp != -1){
            info[i].push_back(temp);
            cin >> temp;
        }
    }

    if(N == temp) N == N;

    return 0;
}