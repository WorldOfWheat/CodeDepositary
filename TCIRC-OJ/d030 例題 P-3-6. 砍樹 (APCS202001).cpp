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

struct node {
    int l, r;
    int x, y;
    bool vis;
};

vector<node> ve;
queue<int> qu;

void _remove(int pos) {
    if (ve[pos].vis) {
        return;
    }
    int l = ve[pos].l;
    int r = ve[pos].r;
    if (ve[pos].x - ve[pos].y >= ve[l].x || ve[pos].x + ve[pos].y <= ve[r].x) {
        ve[pos].vis = true;
        qu.push(pos);
        ve[l].r = r;
        ve[r].l = l;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    ve.resize(n+2);
    ve[0].x = 0;
    ve[0].y = 1e18;
    ve[0].vis = false;
    rep2 (i, 1, n) {
        cin >> (ve[i].x);
    }
    rep2 (i, 1, n) {
        cin >> (ve[i].y);
    }
    ve[n+1].x = m;
    ve[n+1].y = 1e18;
    ve[n+1].vis = false;
    rep2 (i, 1, n) {
        ve[i].l = i - 1;
        ve[i].r = i + 1;
        ve[i].vis = false;
    }
    rep2 (i, 1, n) {
        _remove(i);
    }
    int ans = 0, maxi = 0;
    while (qu.size()) {
        int top = qu.front();
        qu.pop();
        ans++;
        maxi = max(maxi, ve[top].y);
        _remove(ve[top].l);
        _remove(ve[top].r);
    }
    cout << ans << sp << maxi << ln;
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

V ve;
V ve2;
stack<int> st;

void solve() {
    int n, m;
    cin >> n >> m;
    ve.resize(n+2);
    ve2.resize(n+2);
    ve[0] = 0;
    ve2[0] = 1e18;
    rep2 (i, 1, n) {
        cin >> (ve[i]);
    }
    rep2 (i, 1, n) {
        cin >> (ve2[i]);
    }
    ve[n+1] = m;
    ve2[n+1] = 1e18;
    st.push(0);
    int ans = 0, maxi = 0;
    rep2 (i, 1, n) {
        if (ve[i] - ve2[i] >= ve[st.top()] || ve[i] + ve2[i] <= ve[i+1]) {
            ans++;
            maxi = max(maxi, ve2[i]);

            while (ve[st.top()] + ve2[st.top()] <= ve[i+1]) {
                ans++;
                maxi = max(maxi, ve2[st.top()]);
                st.pop();
            }
        }
        else {
            st.push(i);
        }
    }
    cout << ans << ln << maxi << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
