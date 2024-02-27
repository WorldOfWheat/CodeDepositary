#include <bits/stdc++.h>
#define int long long
#define ln '\n'
#define sp " "

using namespace std;

vector<int> ve;
vector<bool> re;
vector<bool> neg;

void solve() {

    int n;
    string str;
    getline(cin, str);
    n = atoi(str.c_str());
    ve.resize(n);
    re.resize(n);
    neg.resize(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        ve[i] = atoi(str.c_str());
        re[i] = atoi(str.substr(str.length() - 5, 5).c_str());
        neg[i] = (str[0] == '-');
        sum += ve[i];
    }
    if (sum == 0) {
        for (int i = 0; i < n; i++) {
            cout << ve[i] << ln;
        }
        return;
    }
    else {
        for (int i = 0; i < n && sum ; i++) {
            if (sum > 0) {
                if (neg[i] && re[i]) {
                    ve[i]--;
                    sum--;
                }
            }
            else {
                if ((!neg[i]) && re[i]) {
                    ve[i]++;
                    sum++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ve[i] << ln;
        }
    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
