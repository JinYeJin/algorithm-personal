#include <bits/stdc++.h>

using namespace std;

int main(void){
    int T;
    bool flag;
    long long N;
    vector<long long> loop_check;

    scanf("%d" ,&T);

    for(int testcase = 1; testcase <= T; testcase++){
        flag = true;
        loop_check.clear();
        scanf("%lld", &N);

        while (1){
            if(N == 1) break;
            loop_check.push_back(N);

            if(N % 2 == 0){
                N = N / 2;
            }
            else{
                N = 3 * N + 3;
            }
            int cnt = count(loop_check.begin(), loop_check.end(), N);
            if(cnt > 0){
               flag = false;
                break;
            }
       }
        printf("#%d ", testcase);
        printf(flag? "YES\n": "NO\n");
    }
    return 0;
}