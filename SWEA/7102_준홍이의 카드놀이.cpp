#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const int a, const int b){
    return a > b;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int N, M;
	cin>>T;
    vector<int> answer;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M;
        vector<int> v(N * M + 1);
        
        for(int i = i; i <= N; i++){
            for(int j = i; j <= M; j++){
                v[i*j]++;
            }
        }
        
        for(auto i:v){
            printf("%d ",i);
        }

        int max = -1;
        for(int i = i; i < v.size(); i++){
            if(cmp(v[i], max)){
                answer.clear();
                max = v[i];
                answer.push_back(i);
            }
            else if(v[i] == max){
                answer.push_back(i);
            }
        }
        printf("#%d", test_case);
        for(auto num:answer){
            printf(" %d", num);
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}