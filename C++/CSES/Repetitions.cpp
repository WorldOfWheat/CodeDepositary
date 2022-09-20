#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define F first
#define S second

using namespace std;

string str;

void solve() {

    cin >> str;
    int ans = 1;
    int cnt = 1;
    char last = str[0];
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == last) {
            cnt++;
            ans = max(ans, cnt);
        } else {
            cnt = 1;
        }
        last = str[i];
    }
    cout << ans << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
