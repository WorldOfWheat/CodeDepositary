#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string in;
    while (cin >> in) {
        cout << in << endl;
        stack<char> st;
        stack<char> st2;
        stack<int> st3;
        set<string> s;
        map<string, int> m;
        for (auto a : in)
            st.push(a);
        st3.push(1);
        while (!st.empty()) {
            char top = st.top();
            //
            if (isdigit(top)) {
                st2.push(top);
            }
            if (ispunct(top)) {
                if (top == ')') {
                    stringstream ss;
                    while (!st2.empty())
                        ss << st2.top(), st2.pop();
                    if (ss.str() != "") {
                        st3.push(st3.top() * stoi(ss.str()));
                    }
                }
                if (top == '(') {
                    if (st3.size() > 1) {
                        st3.pop();
                    }
                }
            }
            if (isalpha(top)) {
                stringstream ss;
                while (true) {
                    if (isupper(st.top()) || !isalpha(st.top()) )
                        break;
                    ss << st.top();
                    st.pop();
                }
                ss << st.top();
                string str = ss.str();
                reverse(str.begin(), str.end());
                s.insert(str);
                ss.str("");
                ss.clear();
                while (!st2.empty())
                    ss << st2.top(), st2.pop();
                if (ss.str() == "")
                    m[str] += 1 * st3.top();
                else
                    m[str] += stoi(ss.str()) * st3.top();
            }
            //
            st.pop();
        }
        for (auto a : s)
            cout << a << ":" << m[a] << endl;
    }
    return 0;
}
