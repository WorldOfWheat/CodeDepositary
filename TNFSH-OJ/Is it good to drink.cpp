#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

string str;
string str2;
string n, m;


void solve() {

    cin >> str >> n >> str2 >> m;

    if (str == str2 && n == m) {
        cout << "GOOD" << "\n";
        return;
    }
    if (str == str2 || n == m) {
        cout << "=~=" << "\n";
        return;
    }
    cout << "OTZ" << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
