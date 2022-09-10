#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;


void solve() {
    string str;
    int n;
    cin >> str >> n;
    stringstream ss;
    for (auto i : str) {
        if (i - '0' == n) {
            continue;
        }
        ss << i;
    }
    str = ss.str();
    int l = 0, r = str.length() - 1;
    while (l < r) {
        if (str[l] != str[r]) {
            cout << "No" << ln;
            return;
        }
        l++;
        r--;
    }
    cout << "Yes" << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
