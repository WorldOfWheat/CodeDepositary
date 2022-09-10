#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n, m;

class dsu {
    public:
        dsu(int x) {
            data.resize(x+1);
            sum.resize(x+1);
            for (int i = 0; i <= x; i++) {
                sum[i] = 1;
                data[i] = i;
            }
        }
        int _maximum = 1;
        int find_root(int x) {
            if (data[x] == x) {
                return x;
            }
            return (find_root(data[x]));
        }
        int connect(int x, int y) {
            int a = find_root(x);
            int b = find_root(y);
            if (a != b) { 
                sum[b]+=sum[a];
                sum[a] = 0;
                _maximum = max(_maximum, sum[b]);
            }
            data[a] = b;
        }
        /*void test() {
            cout << endl;
            cout << sum.capacity() << endl;
            for (int i = 0; i < 7; i++) {
                cout << sum[i] << " ";
            }
        }*/
    private:
        vector<int> data;
        vector<int> sum;
};

void solve() {

    dsu ds(n);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        ds.connect(a, b);
    }
    cout << ds._maximum << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m) {
        solve();
    }

    return 0;
}
