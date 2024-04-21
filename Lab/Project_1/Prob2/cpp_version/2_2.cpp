// 状态：string  target = "12345678x"
// queue：存入搜索到的状态
// dist：hash_map，记录起始状态到每个状态的距离（移动步数）
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
const int N = 1000100;
unordered_map<string, int>  dist;
string q[N];
int hh = 0, tt = -1;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int bfs(string begin)
{
    q[++tt] = begin;
    dist[begin] = 0;

    while (hh <= tt)
    {
        string state = q[hh++];
        if (state == "12345678x")  return dist[state];
        int x, y;
        for (int i = 0; i < state.size(); i ++)
        {
            if (state[i] == 'x')
            {
                x = i / 3;
                y = i % 3;
                break;
            }
        }

        for (int i = 0; i < 4; i ++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            string next_state = state;
            if (0 <= next_x && next_x < 3 && 0 <= next_y && next_y < 3)
            {
                swap(next_state[next_x * 3 + next_y], next_state[x * 3 + y]);
                if (dist.find(next_state) == dist.end())
                {
                    q[++tt] = next_state;
                    dist[next_state] = dist[state] + 1;
                }
            }
        }
    }

    return -1;
}

int main()
{
    string begin;
    for (int i = 1; i <= 9l; i ++)
    {
        string c;
        cin >> c;
        begin += c;
    }

    printf("%d\n", bfs(begin));

    return 0;
}