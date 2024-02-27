#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<int, vector<pair<int, int>>> graph;
int maxinum;

void dfs(int start, int last, int cost) {
    maxinum = max(maxinum, cost);
    for (auto a : graph[start]) {
        dfs(a.first, last, cost+a.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char in_start;
    while (cin >> in_start) {
        graph.clear();
        maxinum = 0;
        int start = (int) in_start - 64;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            char in_a, in_b;
            int a, b, c;
            cin >> in_a >> in_b >> c;
            a = (int) in_a - 64;
            b = (int) in_b - 64;
            graph[a].push_back({b, c});
        }
        dfs(start, 0, 0);
        cout << maxinum << endl;
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int weight[100][100];
vector<int> graph[100];
vector<int> path;
int cost;

void dfs(int start, int last) {
    cost += weight[last][start];
    for (int &a : graph[start]) {
        dfs(a, start);
    }
    path.push_back(cost);
    cost -= weight[last][start];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char char_start;
    while (cin >> char_start) {
        memset(&weight, 0, sizeof(weight));
        memset(&graph, 0, sizeof(graph));
        memset(&path, 0, sizeof(path));
        cost = 0;
        int start = (int) char_start - 64;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            char char_a, char_b;
            int a, b, c;
            cin >> char_a >> char_b >> c;
            a = (int) char_a - 64;
            b = (int) char_b - 64;
            graph[a].push_back(b);
            weight[a][b] = max(weight[a][b], c);
        }
        dfs(start, 0);
        sort(path.begin(), path.end());
        reverse(path.begin(), path.end());
        cout << path[0] << endl;
    }
    return 0;
}
