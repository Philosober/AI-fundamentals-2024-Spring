// 终点T第一次出队，即确定了S到T的最短路；但其他点可能会多次更新，第一次出队不一定可以确定为最短路点
// 启发式函数的估计为每个state中所有数字到正确位置的曼哈顿距离
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>

#define x first
#define y second

using namespace std;
typedef pair<int, string>  PIS;   // {dist + f, state}
priority_queue<PIS, vector<PIS>, greater<PIS>> q;
unordered_map<string, int> dist;  // {state, 从起点到当前状态的距离(会不断更新，不一定为最短路)}
unordered_map<string, pair<string, char>> pre;   // {cur, {prev, op}}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char op[] = {'d', 'r', 'u', 'l'};
string T = "12345678x";

int f(string state)
{
    int res = 0;
    for (int i = 0; i < 9; i ++)
    {
        if (state[i] == 'x')  continue;
        int pos = state[i] - '1';   // 正确的位置
        res += abs(i / 3 - pos / 3) + abs(i % 3 - pos % 3);
    }
    return res;
}

void bfs(string start)
{
    q.push({0 + f(start), start});
    dist[start] = 0;

    while (q.size())
    {
        PIS t = q.top();
        q.pop();
        if (t.y == T)  break;
        int pos = t.y.find('x');
        int x = pos / 3;
        int y = pos % 3;

        for (int i = 0; i < 4; i ++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (0 <= new_x && new_x <= 2 && 0 <= new_y && new_y <= 2)
            {
                string next = t.y;
                int new_pos = new_x * 3 + new_y;
                swap(next[pos], next[new_pos]);
                if (!dist.count(next) || dist[next] > dist[t.y] + 1)
                {
                    dist[next] = dist[t.y] + 1;
                    q.push({dist[next] + f(next), next});
                    pre[next] = {t.y, op[i]};
                }
            }
        }
    }

    string res;
    string t = T;
    while (t != start)
    {
        res += pre[t].second;
        t = pre[t].first;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main()
{
    string start;
    char c;
    while (cin >> c)   start += c;
    // 求逆序数
    int tao = 0;
    for (int i = 0; i < 9; i ++)
    {
        if (start[i] == 'x')  continue;
        for (int j = 0; j < i; j ++)
        {
            if (start[j] == 'x')  continue;
            if (start[j] > start[i])  tao ++;
        }
    }
    if (tao % 2)   printf("unsolvable");
    else  bfs(start);
    return 0;
}