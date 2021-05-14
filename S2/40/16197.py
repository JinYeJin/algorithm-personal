from queue import Queue
import sys

sys.stdin = open("input/16197.txt")

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def boundary(c):
    return c[0] >= 0 and c[0] < N and c[1] >= 0 and c[1] < M

def move(aq, bq):
    # c = q.get()

    a = aq.get()
    b = bq.get()

    for d in range(4):
        na = (a[0] + dy[d], a[1] + dx[d])
        nb = (b[0] + dy[d], b[1] + dx[d])

        bound_a = boundary(na)
        bound_b = boundary(nb)
        if bound_a ^ bound_b:
            print("aaa")
            return True
        if (not visited_a[na[0]][na[1]]) and bound_a:
            if board[na[0]][na[1]] == '.':
                visited_a[na[0]][na[1]] = True
                aq.put(na)
        if (not visited_b[nb[0]][nb[1]]) and bound_b:
            if board[nb[0]][nb[1]] == '.':
                visited_b[nb[0]][nb[1]] = True
                bq.put(nb)
    return aq, bq

N, M = map(int, input().split())
print(M, N)

board = []

a = None
b = None
flag = True

visited_a = [[False] * M for _ in range(N)]
visited_b = [[False] * M for _ in range(N)]

for n in range(N):
    temp = input()
    temp_list = []
    for m in range(M):
        temp_list.append(temp[m])
        if temp[m] == 'o':
            if flag:
                a = (n, m)
                flag = False
            else: b = (n, m)
    board.append(temp_list)

print(board, a, b)

aq = Queue()
bq = Queue()

aq.put(a)
bq.put(b)

answer = 0 

while(answer < 10):
    aq, bq = move(aq, bq)
    if aq == True:
        break
    answer += 1


print(answer)