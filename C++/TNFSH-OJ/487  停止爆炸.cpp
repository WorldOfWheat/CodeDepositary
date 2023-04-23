#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x;
    int y;
};

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
vector<vector<int>> world;
vector<vector<int>> visited;
queue<Point> bfs;
int n, m;
Point creeper;
Point player;

void solve() 
{
    cin >> n >> m;
    world.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> world[i][j];
        }
    }
    cin >> creeper.x >> creeper.y;
    cin >> player.x >> player.y;
    creeper.x -= 1;
    creeper.y -= 1;
    player.x -= 1;
    player.y -= 1;
    
    bfs.push(creeper);
    visited[creeper.x][creeper.y] = 1;
    while (bfs.size())
    {
        Point top = bfs.front();
        bfs.pop();

        int distance = abs(top.x - player.x) + abs(top.y - player.y);
        if (distance <= 3)
        {
            cout << "yes" << '\n';
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int x = top.x + dx[i];
            int y = top.y + dy[i];
            if (!(x >= 0 && x < n))
            {
                continue;
            }
            if (!(y >= 0 && y < m))
            {
                continue;   
            }
            Point next;
            next.x = x;
            next.y = y;
            int diff = world[next.x][next.y] - world[top.x][top.y];
            if (!(diff <= 1 && diff >= -2)) 
            {
                continue;
            }
            if (visited[next.x][next.y] == 1)
            {
                continue;
            }

            bfs.push(next);
            visited[next.x][next.y] = 1;
        }
    }

    cout << "no" << '\n';
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
