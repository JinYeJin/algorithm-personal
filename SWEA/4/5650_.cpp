/*  
    5660.삼성 기출 핀볼 게임
    2020-03-16
    진예진
*/

#include<iostream>
#include<vector>

using namespace std;

int N;
vector<vector<int>> pinball(100, vector<int>(100, 0));

int main(int argc, char** argv)
{
	int test_case;
	int T;
    FILE *stream;

    stream = freopen("5650_sample_input.txt", "r", stdin);

    if(!stream)
        perror("freopen");

    printf("A");

    scanf("%d", &T);
    printf("%d", T);

	for(test_case = 1; test_case <= T; ++test_case)
	{
        // -1 블랙홀(최대 5개). 0 빈공간, 1 ~ 5 블록, 6 ~ 10 웜홀(최대 5쌍)
        scanf("%d", &N);
        printf("ddf");

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &pinball[i][j]);
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                printf("%d ", pinball[i][j]);
            }
            printf("\n");
        }

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}