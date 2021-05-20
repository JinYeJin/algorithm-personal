def solution(n, k, cmd):
    answer = ''
    removed = []
    arr = [True for _ in range(n)]

    last = -1
    i = 1
    for c in cmd:
        print("-----")
        print("try", i)
        i+= 1
        print(c)
        if len(c) > 1:
            c, num = c.split()
            num = int(num)
            if c == "U":
                direction = -1
            if c == 'D':
                direction = 1

            while (num):
                k += direction
                if arr[k] == True:
                    num -= 1
        else:
            if c == "C":
                arr[k] = False
                removed.append(k)
                if k == n-1:  # 마지막이면 위로
                    direction = -1
                else:
                    direction = 1
                while (True):
                    k += direction
                    if arr[k] != False:
                        break
            if c == "Z":
                print(removed)
                last = removed.pop()
                arr[last] = True
        print(k, arr)

    for i in range(n):
        if arr[i]:
            answer += 'O'
        else:
            answer += 'X'
    return answer

cccc = ["D 2.py", "C", "U 3", "C", "D 4", "C", "U 2.py", "Z", "Z", "U 1", "C"]
solution(8, 2, cccc)