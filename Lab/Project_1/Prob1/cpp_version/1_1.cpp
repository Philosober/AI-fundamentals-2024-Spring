#include <iostream>
#include <cstring>

using namespace std;
const int N = 100010;
int q[N], hh = 0, tt = -1;
int g[N], dist[N], e[N], ne[N], idx;
int n, m;

void add(int a, int b)
{
    idx ++, e[idx] = b, ne[idx] = g[a], g[a] = idx;
}

int bfs()
{
    q[++tt] = 1;
    dist[1] = 0;

    while (hh <= tt)
    {
        int node = q[hh++];
        if (node == n)  return dist[n];

        for (int cur = g[node]; cur != -1; cur = ne[cur])
        {
            int j = e[cur];
            if (dist[j] == -1)  q[++tt] = j, dist[j] = dist[node] + 1;
        }
    }

    return -1;
}


int main()
{
    memset(g, -1, sizeof g);
    memset(dist, -1, sizeof dist);
    cin >> n >> m;
    int a, b;
    while (m --)
    {
        cin >> a >> b;
        add(a, b);
    }

    printf("%d\n", bfs());

    return 0;
}