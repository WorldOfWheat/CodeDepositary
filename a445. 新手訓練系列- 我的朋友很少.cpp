#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, m, k;

class dsu {
    public:
        dsu() {
            for (int i = 0; i <= 1e5; i++) {
                data[i] = i;
            }
        }
        int find_root(int x) {
            if (data[x] == x) {
                return x;
            }
            return (find_root(data[x]));
        }
        void connect(int x, int y) {
            int a = find_root(data[x]);
            int b = find_root(data[y]);
            data[a] = b;
        }
        bool is_connected(int x, int y) {
            int a = find_root(x);
            int b = find_root(y);
            return a == b;
        }
    private:
        int data[(int) 1e5+1] = {0};
};

void solve() {

    cin >> n >> m >> k;
    dsu ds;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ds.connect(a, b);
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        if (ds.is_connected(a, b)) {
            cout << ":)" << "\n";
        } else {
            cout << ":(" << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
