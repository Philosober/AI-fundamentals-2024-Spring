#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define dis first
#define node second

using namespace std;
const int N = 200010;
typedef pair<int, int> PII;  // {dis, node}
priority_queue<PII, vector<PII>, greater<PII>>  q;
int e[N], ne[N], w[N], idx;
int g[N], dist[N], n, m;
bool st[N];

void add(int a, int b, int c)
{
    idx ++; e[idx] = b; ne[idx] = g[a]; g[a] = idx; w[idx] = c;
}

void Dijkstra()
{
    memset(dist, 0x3f3f3f3f, sizeof dist);
    dist[1] = 0;
    q.push({0, 1});

    while (q.size())
    {
        // 1
        auto t = q.top();
        q.pop();

        // 2
        if (st[t.node])   continue;
        st[t.node] = 1;

        // 3
        for (int cur = g[t.node]; cur != -1; cur = ne[cur])
        {
            int j = e[cur];
            if (dist[j] > t.dis + w[cur])
            {
                dist[j] = t.dis + w[cur];
                q.push({dist[j], j});
            }
        }
    }
}

int main()
{
    memset(g, -1, sizeof g);
    scanf("%d%d", &n, &m);
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d\n", &a, &b, &c);
        add(a, b, c);
    }
    Dijkstra();
    if (dist[n] >= 0x3f3f3f3f / 2)   printf("-1");
    else printf("%d", dist[n]);
    return 0;
}