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
stack<int> st;

void solve() {
    int n;
    cin >> n;
    ve.resize(n+1);
    ve[0] = 1e18;
    st.push(0);
    rep2 (i, 1, n) {
        cin >> ve[i];
    }
    int ans = 0;
    rep2 (i, 1, n) {
        while (ve[st.top()] <= ve[i]) {
            st.pop();
        }
        ans += i - st.top();
        st.push(i);
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

//////////////////////////////////////////////////////////////

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

stack<pii> st;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    st.push({1e18, 0});
    rep2 (i, 1, n) {
        int in;
        cin >> in;
        while (st.top().F <= in) {
            st.pop();
        }
        ans += i - (st.top().S);
        st.push({in, i});
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
