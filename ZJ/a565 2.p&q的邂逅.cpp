#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

stack<char> st;
stack<char> st2;

void solve() {

    while (st.size()) {
        st.pop();
    }
    while (st2.size()) {
        st2.pop();
    }

    string str;
    cin >> str;
    for (auto a : str) {
        if (isalpha(a)) {
            st.push(a);
        }
    }
    int ans = 0;
    while (st.size()) {
        char top = st.top();
        st.pop();
        if (st2.size()) {
            if (top == 'p' && st2.top() == 'q') {
                ans++;
                st2.pop();
            }
            else {
                st2.push(top);
            }
        }
        else {
            st2.push(top);
        }
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
