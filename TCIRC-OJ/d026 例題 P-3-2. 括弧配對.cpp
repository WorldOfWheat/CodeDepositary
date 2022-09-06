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

string str;

void solve() {
    stack<char> st;
    rrep (i, str.length()-1, 0) {
        char top = str[i];
        if (top == ')' || top == ']' || top == '}') {
            st.push(top);
            continue;
        }
        if (st.empty()) {
            st.push(top);
            continue;
        }
        if (top == '(' && st.top() == ')') {
            st.pop();
            continue;
        }
        if (top == '[' && st.top() == ']') {
            st.pop();
            continue;
        }
        if (top == '{' && st.top() == '}') {
            st.pop();
            continue;
        }
    }
    cout << (st.empty() ? "Yes" : "No") << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> str) solve();

    return 0;
}
