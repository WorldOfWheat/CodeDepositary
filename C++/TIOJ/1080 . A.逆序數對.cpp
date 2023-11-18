#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

int n;
int times;
vector<int> ve;

class BIT_tree {
    public:
        BIT_tree(int x) {
            _size = x + 1;
            data.resize(_size);
        }
        void update(int pos, int value) {
            for (int i = pos; i <= _size; i+=getLowbit(i)) {
                data[i] += value;
            }
        }
        int query(int pos) {
            int res = 0;
            for (int i = pos; i >= 1; i-=getLowbit(i)) {
                res += data[i];
            }
            return res;
        }
    private:
        int _size;
        vector<int> data;
        int getLowbit(int x) {
            return (x & -x);
        }
};

void disc(vector<int> &x) {
    vector<int> a;
    a.assign(x.begin(), x.end());
    sort(a.begin(), a.end());
    for (auto it = x.begin(); it != x.end(); it++) {
        auto it2 = lower_bound(a.begin(), a.end(), *it);
        *it = distance(a.begin(), it2) + 1;
    }
}

void solve() {

    BIT_tree bit(n);
    ve.resize(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ve[i] = a;
    }
    disc(ve);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int top = ve[i];
        ans += i - (bit.query(top));
        bit.update(top, 1);
    }
    cout << "Case #" << (++times) << ": " << ans <<ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n, n) solve();

    return 0;
}
