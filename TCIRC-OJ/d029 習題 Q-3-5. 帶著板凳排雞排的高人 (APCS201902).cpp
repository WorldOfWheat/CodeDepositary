#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

V ve;
V ve2;
V ve3;
stack<int> st;
multimap<int, int> mma;

void solve() {
    int n;
    cin >> n;
    ve.resize(n+1);
    ve2.resize(n+1);
    ve3.resize(n+1);
    rep2 (i, 1, n) {
       cin >> ve[i];
    }
    rep2 (i, 1, n) {
        cin >> ve2[i];
        ve3[i] = ve[i] + ve2[i];
    }
    int ans = 0;
    st.push(1e18);
    rep2 (i, 1, n) {
        auto it = mma.upper_bound(ve3[i]);
        if (it == mma.end()) {
            ans += (i-1);
        }
        else {
            ans += (i - (*it).S - 1);
        }
        while (st.top() <= ve[i]) {
            mma.erase(mma.lower_bound( st.top() ));
            st.pop();
        }
        st.push(ve[i]);
        mma.insert({ve[i], i});
    }
    cout << ans << ln;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
