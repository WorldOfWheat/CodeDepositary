#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

string str;

void solve() {

    cin >> str;
    int mid = str.length() >> 1;
    int l = 0, r = str.length() - 1;
    while (l <= r) {
        if (str[l] != str[r]) {
            cout << "no";
            return;
        }
        l++;
        r--;
    }
    cout << "yes";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
