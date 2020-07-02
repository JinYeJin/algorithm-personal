/*
2020-07-02 진예진
[백준 2196 로봇 조종하기] https://www.acmicpc.net/problem/2169
참고 https://m.blog.naver.com/PostView.nhn?blogId=occidere&logNo=220808155184&proxyReferer=https:%2F%2Fwww.google.com%2F
*/

#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\5\\input\\2196_input.txt", "r", stdin);
    if(!stream) perror("freopne");

	int i, j, n, m; 
	int map[1001][1001] = { 0, };
    int d[1001][1001] = { 0, };
    int tmp[2][1001] = { 0, };

    scanf("%d%d", &n, &m);

	for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            scanf("%d", &map[i][j]);
	
    d[1][1] = map[1][1];

	for (j = 2; j <= m; j++) d[1][j] += map[1][j] + d[1][j - 1];
	
    for (i = 2; i <= n; i++) {
		tmp[0][0] = d[i - 1][1];
		for (j = 1; j <= m; j++)
		    tmp[0][j] = max(tmp[0][j - 1], d[i - 1][j]) + map[i][j];		
		
		tmp[1][m + 1] = d[i - 1][m];
		for (j = m; j >= 1; j--)
		    tmp[1][j] = max(tmp[1][j + 1], d[i - 1][j]) + map[i][j];				
		
		for (int j = 1; j <= m; j++)
		    d[i][j] = max(tmp[0][j], tmp[1][j]);	
	}

	printf("%d", d[n][m]);
    return 0;
}