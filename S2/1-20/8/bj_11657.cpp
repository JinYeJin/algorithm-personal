#include <cstdio>
#include <vector>
using namespace std;

struct DATA {
	int v, nv, w;
};
const int INF = 1e9;
int n, m;
vector<DATA> graph;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v, nv, w;
		scanf("%d %d %d", &v, &nv, &w);
		graph.push_back({ v, nv, w });
	}
	vector<int> bf(n + 1, INF);
	bf[1] = 0;
	bool minus = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v = graph[j].v;
			int nv = graph[j].nv;
			int w = graph[j].w;
			if (bf[v] != INF && bf[nv] > bf[v] + w) {
				bf[nv] = bf[v] + w;
				if (i == n - 1) { // 계속 갱신 중이면
					minus = true;
				}
			}
		}
	}
	if (minus) {
		printf("-1\n");
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (bf[i] != INF) {
				printf("%d\n", bf[i]);
			}
			else {
				printf("-1\n");
			}
		}
	}
	return 0;
}