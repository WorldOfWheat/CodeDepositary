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
map<char, int> mp = {
{'+', 1},
{'-', 1},
{'*', 2},
{'/', 2},
{'%', 2},
{'(', 0},
{')', 0}
};

int simpleCal(int x, int y, char symbol) {
    switch (symbol) {
        case '+':
            return (x + y);
            break;

        case '-':
            return (x - y);
            break;

        case '*':
            return (x * y);
            break;

        case '/':
            return (x / y);
            break;
        case '%':
            return (x % y);
            break;
    }
}

void solve() {
    stringstream ss;
    for (auto i : str) {
        if (i == ' ') {
            continue;
        }
        ss << i;
    }
    str = ss.str();
    stack<int> st;
    stack<char> st2;
    stringstream num;
    rep (i, 0, str.length()) {
        char top = str[i];
        if (isdigit(top)) {
            num << top;
            if (i + 1 == str.length()) {
                st.push(atoi(num.str().c_str()));
                num.str("");
                num.clear();
            }
            continue;
        }
        if (num.str().size() > 0) {
            st.push(atoi(num.str().c_str()));
            num.str("");
            num.clear();
        }
        if (top == ')') {
            while (st2.top() != '(') {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                char c = st2.top();
                st2.pop();
                st.push(simpleCal(b, a, c));
            }
            st2.pop();
            continue;
        }
        if (st2.empty() || top == '(' || mp[st2.top()] < mp[top]) {
            st2.push(top);
            continue;
        }
        while (st2.size() && mp[st2.top()] >= mp[top]) {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            char c = st2.top();
            st2.pop();
            st.push(simpleCal(b, a, c));
        }
        st2.push(top);
    }
    while (st2.size()) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        char c = st2.top();
        st2.pop();
        st.push(simpleCal(b, a, c));
    }
    cout << (st.top()) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (getline(cin, str)) solve();

    return 0;
}
