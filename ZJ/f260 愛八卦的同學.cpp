#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln '\n'
#define sp " "

using namespace std;

int n, m;

class DSU {

    public:
        int cnt;
        DSU(int x) {
            _size = x;
            cnt = _size;
            data.resize(_size+1);
            for (int i = 0; i <= _size; i++) {
                data[i] = i;
            }
        }
        void update(int x, int y) {
            int &a = data[query(x)];
            int b = query(y);
            if (a != b) {
                cnt--;
            }
            a = b;
        }


    private:
        int _size;
        vector<int> data;
        int query(int x) {
            if (data[x] == x) {
                return x;
            }
            return data[x] = query(data[x]);
        }
};

void solve() {

    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.update(a, b);
    }
    cout << (dsu.cnt) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m) solve();

    return 0;
}
