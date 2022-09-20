#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

class bit{
    public:
        bit(int x) {
            data.resize(x+1);
            _size = x;
        }
        void update(int x, int y) {
            for (int i = x; i <= _size; i+=lowbit(i)) {
                data[i] += y;
            }
        }
        int query(int x) {
            int result = 0;
            for (int i = x; i >= 1; i-=lowbit(i)) {
                result += data[i];
            }
            return result;
        }
        void test(int x) {
            cout << (lowbit(x)) << endl;
        }

    private:
        vector<int> data;
        int _size;
        int lowbit(int x) {
            return (x & -x);
        }
};

int n;
vector<int> ve;
vector<int> ve2;

void solve() {

    bit bi(n);
    ve.resize(n+1);
    ve2.resize(n+1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        ve[i] = a;
        ve2[i] = a;
    }
    sort(ve2.begin(), ve2.end());
    for (int i = 1; i <= n; i++) {
        ve[i] = distance(ve2.begin(), lower_bound(ve2.begin(), ve2.end(), ve[i]) );
    }
    for (int i = 1; i <= n; i++) {
        int a = ve[i];
        cout << (i - bi.query(a-1) ) << endl;
        bi.update(a, 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
