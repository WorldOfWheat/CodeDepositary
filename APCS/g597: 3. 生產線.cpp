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
vector<int> ve_order;

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

    BIT_tree bit(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bit.update(a, c);
        bit.update(b+1, -c);
    }

    ve_order.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve_order[i];
    }
    sort(ve_order.begin(), ve_order.end());

    for (int i = 1; i <= n; i++) {
        int a = bit.query(i);
        if (a != 0) ve.push_back(a);
    }
    sort(ve.rbegin(), ve.rend());
    int ans = 0;
    for (int i = 0; i < ve.size(); i++) {
        ans += ve_order[i] * ve[i];
    }
    cout << ans << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
