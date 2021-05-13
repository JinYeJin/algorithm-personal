from queue import Queue


def boundary(x, y):
    return (x >= 0) and (x < C) and (y >= 0) and (y < R)


def solution(places):
    answer = []
    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]

    visited = []

    for place in places:
        global R
        global C
        R = len(place)
        C = len(place[0])
        exit = False

        for r in range(len(place)):
            for c in range(len(place[r])):
                path = Queue()
                num = Queue()
                visited = [[False] * len(place[r]) for _ in range(len(place))]
                if place[r][c] == 'P':
                    path.put({'r': r, 'c': c, 'num': 0})
                    num.put(0)
                    visited[r][c] = True
                    # print(visited)

                    # BFS
                    while path.empty() == False:
                        cur = path.get()
                        # cnum = num.get()
                        # print('r {} c {}'.format(cur[0], cur[1]))
                        if cur['num'] > 3:
                            continue
                        if r != cur['r'] and c != cur['c']:
                            if (cur['num'] > 0) and (place[cur['r']][cur['c']] == 'P'):
                                # print('break y {} x {}'.format(r, c), end=' ')
                                # print('break y {} x {}'.format(cur['r'], cur['c']))
                                answer.append(0)
                                exit = True
                                break

                        for d in range(4):
                            ny = cur['r'] + dy[d]
                            nx = cur['c'] + dx[d]
                            # 바운더리 체크, 방문체크
                            if boundary(nx, ny) and (visited[ny][nx] == False):
                                # 파티션이 아니면 이동
                                if cur['num'] < 2:
                                    if place[ny][nx] != 'X':
                                        visited[ny][nx] = True
                                        path.put({'r': ny, 'c': nx, 'num': cur['num'] + 1})
                                        # print('222 ny {} nx {}'.format(ny, nx))
                                        # num.put((cnum + 1))

                if exit: break
            if exit: break
        if exit:
            continue
        else:
            answer.append(1)
    return answer