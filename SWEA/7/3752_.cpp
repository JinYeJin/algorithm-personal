#include <stdio.h>
#include <set>

using namespace std;

int N, K;
int numbers[100];
int choice[100];
set<int> answer_set;

void combination(int number, int idx){
    if(idx >= K){
        int answer = 0;
        for(int i = 0; i < K; i++){           
            answer += choice[i];
            printf("%d ", choice[i]);
            answer_set.insert(answer);
        }
        printf("answer: %d\n", answer);
        return;
    }
    if(number >= N) return;

    choice[idx] = numbers[number];
    combination(number + 1, idx + 1);
    combination(number + 1, idx);
}

int main(void){
    int T;
    FILE *stream;

    stream = freopen("SWEA\\7\\3752_input.txt", "r", stdin);

    if(!stream)
        printf("freopen");

    scanf("%d", &T);

    for(int testcase = 1; testcase <= T; testcase++){
        answer_set.clear();
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%d", &numbers[i]);
        }

        for(int i = 1; i <= N; i++){
            K = i;
            combination(0, 0);
            if (i == N) printf("#%d %d\n", testcase, answer_set.size()+1);
        }

        for(auto x: answer_set){
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}