from collections import deque

N = 100010
M = 2 * N
graph = [-1] * N
e = [0] * M
ne = [0] * M
distance = [-1] * N
idx = 0


def add(a,b):
    global idx
    idx += 1
    e[idx] = b
    ne[idx] = graph[a]
    graph[a] = idx


def bfs():
    queue = deque()
    queue.append(1) # 队列中存储着节点编号
    distance[1] = 0

    while queue:
        node = queue.popleft()
        d = distance[node]
        if node == n:
            return d
        cur = graph[node]
        while cur != -1:
            j = e[cur]
            if distance[j] == -1:
                queue.append(j)
                distance[j] = d + 1
            cur = ne[cur]
    return -1



if __name__ == "__main__":
    n,m = map(int,input().split())
    while m > 0:
        a,b = map(int,input().split())
        add(a,b)
        m -= 1

    dis = bfs()
    print(dis)