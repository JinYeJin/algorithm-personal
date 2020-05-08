#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a.size() > b.size();
}

int main(){
    vector<int> temp;
    vector<vector<int>> tuples;
    
            
    //sort(tuples.begin(), tuples.end(), cmp);
    
    for(int i = 0; i < tuples.size(); i++){
        for(int j = 0; j < tuples[i].size(); j++){
            printf("%d ", tuples[i][j]);
        }
        printf("0\n");
    }
    printf("a");
    return 0;
}