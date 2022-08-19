#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

void solve() {

    string str;
    cin >> str;
    stringstream ss;
    bool flag = false;
    stringstream ss2;
    for (int i = 0; i < str.length(); i++) {
        char top = str[i];
        if (!ispunct(top)) {
            ss2 << top;
        }
        else {
            if (!flag) {
                ss << ss2.str();
            }
            else {
                string temp = ss2.str();
                reverse(temp.begin(), temp.end());
                ss << temp;
            }
            if (top == '+') {
                flag = false;
            }
            else {
                flag = true;
            }
            ss2.str("");
            ss2.clear();
        }
    }
    if (!flag) {
        ss << ss2.str();
    }
    else {
        string temp = ss2.str();
        reverse(temp.begin(), temp.end());
        ss << temp;
    }
    cout << ss.str() << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
