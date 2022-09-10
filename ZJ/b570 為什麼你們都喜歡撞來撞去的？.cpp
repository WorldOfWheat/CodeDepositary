#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x > z; x--)
#define ln "\n"
#define sp " "
#define MAX (int) 1e6 + 1

using namespace std;

vector<pii> ve(MAX);
vector<int> ve2;
bitset<MAX> bs;
stack<int> st;

class DSU {

    public:

        int cnt;

        DSU(int x) {
            cnt = x;
            _size = x + 1;
            data.resize(_size);
            rep (i, 0, _size) {
                data[i] = i;
            }
        }

        void update(int x, int y) {
            int a = query(x);
            int b = query(y);
            if (a != b) {
                cnt--;
            }
            data[a] = b;
        }

        int query(int x) {
            if (data[x] == x) {
                return x;
            }
            return data[x] = query(data[x]);
        }

    private:

        int _size;
        vector<int> data;
};

void solve() {

    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    rep2 (i, 1, m) {
        int a, b;
        cin >> a >> b;
        ve[i] = {a, b};
    }

    int k;
    cin >> k;

    rep (i, 0, k) {
        int a;
        cin >> a;
        ve2.pb(a);
        bs[a] = 1;
    }
    rep2 (i, 1, m) {
        if (!bs[i]) {
            auto [f, s] = ve[i];
            dsu.update(f, s);
        }
    }
    st.push(dsu.cnt);
    while (ve2.size() > 1) {
        int top = ve2.back();
        ve2.pop_back();
        auto [f, s] = ve[top];
        dsu.update(f, s);
        st.push(dsu.cnt);
    }
    while (st.size()) {
        cout << (st.top()) << ln;
        st.pop();
    }


}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
