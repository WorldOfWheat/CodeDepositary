#include <bits/stdc++.h>
#define int long long
#define mn 5000000

using namespace std;
__attribute__((optimize("-O3")))

int n;
vector<int> v;
int visited[mn];
int mini = mn;

void dfs(int x, int y, int z) {
    if (y == v.size()) {
        mini = min(mini, z);
        return;
    }
    int a = x + v[y];
    int b = x - v[y];
    visited[a-1]++;
    dfs(a, y+1, z + (visited[a-1] == 1) );
    visited[a-1]--;

    visited[b-1]++;
    dfs(b, y+1, z + (visited[b-1] == 1) );
    visited[b-1]--;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0 ; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    visited[mn/2-1]++;
    dfs(mn/2, 0, 0);
    cout << mini+1 << "\n";

    return 0;
}
