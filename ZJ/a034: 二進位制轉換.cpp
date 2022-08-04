#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n;

void solve() {

    bitset<64> bs(n);
    string str = bs.to_string();
    while (str[0] == '0') {
        str = str.substr(1);
    }
    cout << (str) << endl;

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
