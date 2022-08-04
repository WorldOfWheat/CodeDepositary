#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;
__attribute__((optimize("-O3")))

vector<int> graph[5+1];
bool path[5+1][5+1];
string str;
set<int> ans;

void dfs(int x, int y, int z) {
    if (z == 0) {
        ans.insert(stoi(str));
        return;
    }
    path[x][y] = true;
    path[y][x] = true;
    for (auto a : graph[x]) {
        if (path[a][x] || path[x][a])
            continue;

        str += to_string(a);
        dfs(a, x, z-1);
        str.pop_back();
    }
    path[x][y] = false;
    path[y][x] = false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(5);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(5);
    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(3);
    graph[4].push_back(5);
    graph[5].push_back(1);
    graph[5].push_back(2);
    graph[5].push_back(3);
    graph[5].push_back(4);
    dfs(1, 0, 8);
    for (auto a : ans) {
        cout << 1 << a << "\n";
    }

    return 0;
}
