#include <bits/stdc++.h>
#define int long long
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define ln '\n'
#define sp " "

using namespace std;

stack<int> st;

void solve() {

    int n;
    cin >> n;
    rep(i, 0, n) {
        int a;
        cin >> a;
        if ( a == 1 ) {
            int b;
            cin >> b;
            st.push(b);
        }
        if ( a == 2 ) {
            cout << (st.size() ? st.top() : -1) << ln;
        }
        if ( a == 3 ) {
            if (st.size()) {
                st.pop();
            }
        }
    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
