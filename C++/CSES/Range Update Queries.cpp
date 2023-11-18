#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n, m;
vector<int> ve;

class BIT_tree {
    public:
        BIT_tree(int x) {
            _size = x + 1;
            data.resize(_size);
        }
        void update(int pos, int value) {
            for (int i = pos; i <=_size; i+=getLowbit(i)) {
                data[i] += value;
            }
        }
        int query(int pos) {
            int result = 0;
            for (int i = pos; i >= 1; i-=getLowbit(i)) {
                result += data[i];
            }
            return (result);
        }
    private:
        vector<int> data;
        int _size;
        int getLowbit(int x) {
            return (x & -x);
        }
};

void solve() {

    cin >> n >> m;
    ve.resize(n+1);
    BIT_tree bit(n);
    ve[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    for (int i = 1; i <= n; i++) {
        bit.update(i, ve[i] - ve[i-1]);
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b, c, d;
            cin >> b >> c >> d;
            bit.update(b, d);
            bit.update(c+1, -d);
        }
        else {
            int b;
            cin >> b;
            cout << (bit.query(b)) << "\n";
        }
    }

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
