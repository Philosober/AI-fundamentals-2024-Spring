N = 510
inf = float("inf")
graph = [[inf] * N for _ in range(N)]
state = [0] * N   # 集合S，记录着哪些点是已经确定的最短路点（到起点到该点）
dis = [inf] * N


def add(a,b,c):
    graph[a][b] = min(graph[a][b],c)


def Dijkstra():
    dis[1] = 0
    for _ in range(1,n+1):
        # 1. 找出不在S中的距离最近的点
        t = -1
        for j in range(1,n+1):
            if (not state[j]) and (t == -1 or dis[t] > dis[j]):
                # j节点是没有确定的最短路点，且dis[t] > dis[j]
                t = j
        # 2. t节点当前的dis可以认为是最短路了
        state[t] = True
        # 3. # 用t节点（新的最短路点）来更新其他点（只能是与t相邻的点）
        for j in range(1,n+1):
            dis[j] = min(dis[j],dis[t]+graph[t][j])

    if dis[n] == inf:
        return -1
    else:
        return dis[n]


if __name__ == "__main__":
    n,m = map(int,input().split())
    while m > 0:
        a,b,c = map(int,input().split())
        add(a,b,c)
        m -= 1

    print(Dijkstra())