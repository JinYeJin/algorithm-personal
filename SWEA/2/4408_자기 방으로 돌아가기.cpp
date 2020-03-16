/*
2020-03-09
Jin Yejin
SWEA 4408 자기 방으로 돌아가기
*/

#include <stdio.h>
#include <vector>

using namespace std;


int main(){
    int testcase;
    int T;
    int N;
    int temp1, temp2;
    FILE *stream;

    stream = freopen("SWEA\\2\\4408_sample_input.txt", "r", stdin);
    if (!stream) printf("freopen");
        
    scanf("%d %d", &T, &N);
    
    vector<pair<int, int>> student_path(N, {0,0});

    for(testcase = 1; testcase <= T; testcase++){

        for(int i = 0; i < N; i++){
            scanf("%d %d", &temp1, &temp2);
            student_path[i] = make_pair(temp1, temp2);
        }

        for(int i = 0; i < student_path.size(); i++){
            printf("%d %d\n", student_path[i].first, student_path[i].second);

        }
    }

    return 0;
}