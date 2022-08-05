#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n;
vector<int> ve;
int times = 1;

class BIT_tree {
    public:
        BIT_tree(int x) {
            _size = x+1;
            data.resize(_size);
        }
        void update(int pos, int x) {
            for (int i = pos; i <= _size; i+=getLowbit(i)) {
                data[i] += x;
            }
        }
        int query(int x) {
            int sum = 0;
            for (int i = x; i >= 1; i-=getLowbit(i)) {
                sum += data[i];
            }
            return sum;
        }

    private:
        vector<int> data;
        int _size;
        int getLowbit(int x) {
            return (x & -x);
        }
};

void discrete(vector<int> &x) {
    vector<int> a;
    a.assign(x.begin(), x.end());
    sort(a.begin(), a.end());
    for (auto it = x.begin(); it != x.end(); it++) {
        auto it2 = lower_bound(a.begin(), a.end(), *it);
        *it = distance(a.begin(), it2) + 1;
    }
}

void solve() {

    ve.resize(n);
    BIT_tree bit(n);

    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }

    discrete(ve);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += i - bit.query(ve[i]);
        bit.update(ve[i], 1);
    }
    cout << "Case #" << (times++) << ": " << ans << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n, n) solve();

    return 0;
}
