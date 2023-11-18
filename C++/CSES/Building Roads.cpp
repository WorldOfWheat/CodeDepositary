#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "
 
using namespace std;
 
int n, m;
 
class DSU {
    public:
        DSU(int x) {
            _size = x;
            data.resize(_size + 1);
            for (int i = 0; i <= _size; i++) {
                data[i] = i;
            }
        }
        void update(int pos, int pos2) {
            data[query(pos)] = query(pos2);
        }
        int query(int pos) {
            if (data[pos] == pos) {
                return pos;
            }
            return data[pos] = query(data[pos]);
        }
    private:
        int _size;
        vector<int> data;
};
 
void solve() {
 
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.update(a, b);
    }
    int ans = 0;
    stringstream ss;
    for (int i = 2; i <= n; i++) {
        if (dsu.query(1) != dsu.query(i)) {
            ans++;
            ss << 1 << sp << i << ln;
            dsu.update(i, 1);
        }
    }
    cout << ans << ln << ss.str() << ln;
 
}
 
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
 
    return 0;
}
