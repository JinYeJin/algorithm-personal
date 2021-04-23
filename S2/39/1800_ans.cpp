#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> p;

int n, m, k;

vector<p> g[1010];
int dist[1010];

bool chk(int x){
	priority_queue<p> pq; pq.push({ 0, 1 });
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	while (pq.size()){
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[now] < cost) continue;
		for (auto i : g[now]){
			int nxt = i.first;
			int nxtCost = cost + (i.second > x);
			if (nxtCost < dist[nxt]){
				dist[nxt] = nxtCost;
				pq.push({ -nxtCost, nxt });
			}
		}
	}

	return dist[n] <= k;
}

int main(){
    FILE *stream = freopen("S2\\39\\input\\1800.txt", "r", stdin);
    if(!stream) perror("freopen");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		int s, e, x; cin >> s >> e >> x;
		g[s].push_back({ e, x });
		g[e].push_back({ s, x });
	}

	int ans = -1;
	int l = 0, r = 1e7;
	while (l <= r){
		int mid = l + r >> 1;
		if (chk(mid)){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout << ans;
}