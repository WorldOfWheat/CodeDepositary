#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<int, vector<pair<int, int>>> graph;
map<int, int> cost;

void dfs(int start, int last, int minuimn) {
    for (auto a : graph[start]) {
        if (a.first == last) continue;
        cost[a.first] = min(a.second, minuimn);
        dfs(a.first, start, min(a.second, cost[a.first]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, vk, q;
    while (cin >> n >> vk >> q) {
        graph.clear();
        cost.clear();
        int maxinum;
        for (int i = 1; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            maxinum = max(maxinum, c);
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        dfs(vk, 0, maxinum);
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (cost[i] >= q) c++;
        }
        cout << c << endl;
    }

    return 0;
}
