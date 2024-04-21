import heapq

INF = float("inf")
N = 150010
ne = [0] * N
e = [0] * N
w = [0] * N
idx = 0
g = [-1] * N
dist = [INF] * N
st = [0] * N


def add(a, b, c):
    global idx
    idx += 1
    e[idx] = b
    ne[idx] = g[a]
    g[a] = idx
    w[idx] = c
    
def Dijkstra(begin):
    q = []   # 小根堆  {dist, node}
    dist[begin] = 0
    heapq.heappush(q, (0, begin))
    
    while q:
        # 1
        t = heapq.heappop(q)
        dis = t[0]
        node = t[1]
        # 2
        if st[node]:
            continue
        st[node] = 1
        # 3
        cur = g[node]
        while cur != -1:
            j = e[cur]
            if dist[j] > dis + w[cur]:
                dist[j] = dis + w[cur]
                heapq.heappush(q, (dist[j], j))
            cur = ne[cur]


if __name__ == "__main__":
    n, m = map(int, input().split())
    for _ in range(m):
        a, b, c = map(int, input().split())
        add(a, b, c)
    Dijkstra(1)
    if dist[n] == INF:
        print("-1")
    else:
        print(dist[n])