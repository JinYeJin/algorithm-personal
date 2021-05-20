import sys
sys.setrecursionlimit(1500)

sys.stdin = open("input/2533.txt")

N = int(sys.stdin.readline())
# N = int(input())

friends = [[] for _ in range(N+1)]
dp = [[0] * 2 for _ in range(N+1)]

for n in range(N-1):
    u, v = map(int, sys.stdin.readline().rstrip().split())
    friends[u].append(v)
    friends[v].append(u)

# print(friends)

def dfs(current, is_early, parents):
    visited[current][is_early] = True
    if friends[current] == None: # 리프노드에 도달
        if is_early:
            dp[current][is_early] = 1
            return dp[current][is_early]
        else:
    for idx, child in enumerate(friends[current]):
        if parents == child: continue
        if(is_early == False): # 자신이 얼리어답터가 아니면 자식노드가 얼리 어답터인 경우만 가져옴
            dp[current][is_early] += dfs(child, True, current) if not visited[child][True] else dp[child][True]
        else:
            dp[current][is_early] += min(
                dfs(child, True, current) if not visited[child][True] else dp[child][True],
                dfs(child, False, current) if not visited[child][False] else dp[child][False]
            )
    # print(dp[current][is_early], current, is_early)
    return dp[current][is_early]

visited = [[False] * 2 for _ in range(N+1)]


dfs(1, True, 0)
dfs(1, False, 0)

# print(dp)

print(dp[1][0] if dp[1][0] < dp[1][1] else dp[1][1])