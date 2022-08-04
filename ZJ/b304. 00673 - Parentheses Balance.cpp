#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string str;
        getline(cin, str);
        if (str == "") {
            cout << "Yes" << endl;
            continue;
        }
        stack<char> s;
        for (auto a : str) {
            s.push(a);
        }
        stack<char> s2;
        s2.push(s.top());
        s.pop();
        while (!s.empty()) {
            switch (s.top()) {
                case ')':
                    s2.push(s.top());
                    break;
                case '(':
                    if (!s2.empty() && s2.top() == ')')
                        s2.pop();
                    else
                        s2.push(s.top());
                    break;
                case ']':
                    s2.push(s.top());
                    break;
                case '[':
                    if (!s2.empty() && s2.top() == ']')
                        s2.pop();
                    else
                        s2.push(s.top());
                    break;
            }
            s.pop();
        }
        cout << (s2.empty() ? "Yes" : "No") << endl;
    }

    return 0;
}
