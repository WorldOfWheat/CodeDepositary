#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> ve;
    ve.resize(n);

    for (int i = 0 ; i < n; i++) {
        cin >> ve[i];
        ve[i]--;
    }

    int k = 0;
    stack<int> st;

    for (int i = 0; i < n; i++) {
       st.push(i);
       while (st.size() && ve[k] == st.top()) {
            st.pop();
            k++;
       }
    }
    cout << (st.size() ? "No" : "Yes") << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
