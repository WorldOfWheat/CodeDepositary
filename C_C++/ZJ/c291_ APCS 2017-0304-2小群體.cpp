#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n;

class dsu {
    public:
        dsu(int x) {
            data = new int[x+1];
            _size = x;
            for (int i = 0; i <= x; i++) {
                data[i] = i;
            }
        }
        int _size;
        int find_root(int x) {
            if (data[x] == x) {
                return x;
            }
            return (find_root(data[x]));
        }
        void connect(int x, int y) {
            int a = find_root(data[x]);
            int b = find_root(data[y]);
            if (a != b) _size--;
            data[a] = b;
        }
        bool is_connected(int x, int y) {
            int a = find_root(x);
            int b = find_root(y);
            return a == b;
        }
    private:
        int* data;
};

void solve() {

    cin >> n;
    dsu ds(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ds.connect(i, a);
    }
    cout << ds._size << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
