#include <bits/stdc++.h>
#define int long long
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

vector<string> table(40+1);
int n;

void solve() {
    cout << (table[n-1]) << ln;
}

void init() {
    string str = "1";
    table[0] = str;
    rep2 (i, 1, 40) {
        stringstream ss;
        int cnt = 0;
        rep (i, 0, str.length()) {
            if (i == 0) {
                cnt++;
                continue;
            }
            if (str[i] == str[i-1]) {
                cnt++;
            }
            else {
                ss << cnt << str[i-1];
                cnt = 1;
            }
        }
        ss << cnt << str[str.length()-1];
        str = ss.str();
        table[i] = str;
        //cout << str << ln;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    while (cin >> n) solve();

    return 0;
}
