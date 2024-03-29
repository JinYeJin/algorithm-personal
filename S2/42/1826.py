import sys

sys.stdin = open("input/1826.txt")
N = int(input())

station = []
dp = [sys.maxsize] * (N+2)

for i in range(N):
    a, b = map(int, input().split())
    station.append({'distance': a, 'fuel': b})

destination, remain_fuel = map(int, input().split())
station.insert(0, {'distance': 0, 'fuel': remain_fuel}) # 인덱스 맞춰주기
station.append({'distance': destination, 'fuel': 0})
dp[0] = 0

for n in range(1, N+2):
    update_fuel = 0
    update_distance = 0
    updated = False
    for i in range(n-1, -1, -1):
        distance = station[n]['distance'] - station[i]['distance']
        fuel = station[n]['fuel'] + station[i]['fuel']
        if distance > station[i]['fuel']: # 올 수 없는 경우
            continue
        if dp[i] + 1 < dp[n]:
            dp[n] = dp[i] + 1
            update_fuel = fuel
            update_distance = distance
            updated = True
    # 결정된 dp 값의 연료양으로 업데이트
    if updated: station[n]['fuel'] = update_fuel - update_distance

print(dp)
print(dp[N+1] if dp[N+1] != sys.maxsize else -1)