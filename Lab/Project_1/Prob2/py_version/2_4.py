import heapq

end = "12345678x"
dist = {}  # {state, dist}
q = []  # {f + g, state}
prev = {}  # {next_state, {op, cur_state}}    追溯一下最优的路径
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
op = ['u', 'r', 'd', 'l']


def f(state):
    # 估计函数
    res = 0
    for i in range(len(state)):
        if state[i] == 'x':
            continue
        pos = int(state[i]) - 1
        res += abs(i // 3 - pos // 3) + abs(i % 3 - pos % 3)

    return res


def A_start(begin):
    heapq.heappush(q, (f(begin) + 0, begin))
    dist[begin] = 0

    while q:
        t = heapq.heappop(q)
        cur_state = t[1]
        if cur_state == end:
            break

        pos = cur_state.find('x')
        x = pos // 3
        y = pos % 3
        for i in range(4):
            new_x = x + dx[i]
            new_y = y + dy[i]
            if 0 <= new_x <= 2 and 0 <= new_y <= 2:
                new_pos = new_x * 3 + new_y
                next_state = list(cur_state)
                next_state[new_pos], next_state[pos] = next_state[pos], next_state[new_pos]
                next_state = "".join(next_state)
                if next_state not in dist or dist[next_state] > dist[cur_state] + 1:
                    dist[next_state] = dist[cur_state] + 1
                    heapq.heappush(q, (dist[next_state] + f(next_state), next_state))
                    prev[next_state] = (op[i], cur_state)

    t = end
    optimum_path = []
    while t != begin:
        optimum_path.append(prev[t][0])
        t = prev[t][1]

    optimum_path.reverse()
    print("".join(optimum_path))


if __name__ == "__main__":
    begin = input().split()

    # 八数码问题有的解的充要条件
    tao = 0
    for i in range(len(begin)):
        if begin[i] == 'x':
            continue
        for j in range(i):
            if begin[j] == 'x':
                continue
            if begin[j] > begin[i]:
                tao += 1
    if tao % 2:
        print("unsolvable")
    else:
        A_start("".join(begin))
