#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

class DSU {
    public:
        DSU(int x) {
            _size = x;
            cnt = _size;
            data.resize(_size + 1);
            for (int i = 0; i <= _size; i++) {
                data[i] = i;
            }
        }
        void connect(int x, int y) {
            int a = query(data[x]);
            int b = query(data[y]);
            data[a] = b;
        }
        bool isConnected(int x, int y) {
            return ( query(x) == query(y) );
        }
    private:
        int _size;
        int cnt;
        vector<int> data;
        int query(int x) {
            if (data[x] == x) {
                return x;
            }
            return query(data[x]);
        }
};

int n, m;

void solve() {

    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.connect(a, b);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (dsu.isConnected(0, i));
    }
    cout << ans << endl;

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
