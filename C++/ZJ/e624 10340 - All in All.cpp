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

string str, str2;

void solve() {
    int l = 0;
    int r = 0;
    while (r < str2.length() && l < str.length()) {
        if (str[l] == str2[r]) {
            l++;
        }
        r++;
    }
    cout << ((l == str.length()) ? "Yes" : "No") << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> str >> str2) solve();

    return 0;
}
