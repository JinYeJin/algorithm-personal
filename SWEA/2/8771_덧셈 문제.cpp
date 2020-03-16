/*
2020-03-09
Jin Yejin
SWEA 8771 덧셈 문제
*/

#include <vector>
#include <stdio.h>
#include <set>

using namespace std;


// N: 숫자의 개수, A: 최소값, B: 최대값
int N;
long long A, B;
set<int> answers;

int dfs(int position, int depth, int sum){
    printf("position: %d, depth: %d, sum: %d\n", position, depth, sum);

    sum += position;

    if(depth > N){
        answers.insert(sum);
        return 0;
    }

    if(position < B) dfs(position + 1, depth + 1, sum);
}


int main(){
    int testcase;
    int T;
    FILE *stream;

    stream = freopen("SWEA\\2\\8771_sample_input.txt", "r", stdin);

    scanf("%d", &T);

    for(testcase = 1; testcase <= T; testcase++){
        scanf("%d %d %d", &N, &A, &B);

        if(A > B){
            printf("#%d %d\n", testcase, 0);
            continue;
        }

        // position, depth, sum
        dfs(A, 1, 0);
        
        printf("#%d %d\n", testcase, answers.size());
    }

    return 0;
}