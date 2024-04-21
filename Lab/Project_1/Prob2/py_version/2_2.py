from collections import deque

def eight_digit(begin):
    dx = [0,1,0,-1]
    dy = [1,0,-1,0]
    queue.append(begin)
    trace[begin] = 0

    while queue:
        cur_state = queue.popleft()
        distance = trace[cur_state]
        if cur_state == target:
            return distance
        k = cur_state.find("x")
        x = k // 3
        y = k % 3

        next_state = list(cur_state)
        for i in range(4):
            a = x + dx[i]
            b = y + dy[i]
            new_k = a * 3 + b
            if 0<=a<3 and 0<=b<3:
                next_state[new_k],next_state[k] = next_state[k],next_state[new_k]
                t = ''.join(next_state)
                if t not in trace:
                    trace[t] = distance + 1
                    queue.append(t)
                next_state[new_k],next_state[k] = next_state[k],next_state[new_k]
    return -1

begin = input().split()
begin = "".join(begin)
target = "12345678x"
trace = {}
queue = deque()
print(eight_digit(begin))