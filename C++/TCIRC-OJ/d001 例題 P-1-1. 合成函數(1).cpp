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

using namespace std;

stack<string> st;
stack<int> st2;

int f(int x) {
    return 2*x - 1;
}
int g(int x, int y) {
    return x + 2*y - 3;
}

void solve() {
    string in;
    while (cin >> in) {
        st.push(in);
    }
    while (st.size()) {
        string top = st.top();
        st.pop();
        if (top[0] == 'f') {
            int a = st2.top();
            st2.pop();
            st2.push(f(a));
            continue;
        }
        if (top[0] == 'g') {
            int a = st2.top();
            st2.pop();
            int b = st2.top();
            st2.pop();
            st2.push(g(a, b));
            continue;
        }
        st2.push(atoi(top.c_str()));
    }
    cout << (st2.top()) << ln;
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}

//////////////////////////////////////////////////////////////////////

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

using namespace std;

int dfs() {
    string str;
    cin >> str;
    if (str[0] == 'f') {
        int a = dfs();
        return 2*a - 1;
    }
    if (str[0] == 'g') {
        int a = dfs();
        int b = dfs();
        return a + 2*b - 3;
    }
    return atoi(str.c_str());
}

void solve() {
    cout << dfs() << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
