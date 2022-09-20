#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define F first
#define S second

using namespace std;

string str;
set<int> se;

void solve() {

    cin >> str;
    sort(str.begin(), str.end());
    stringstream ss;
    int cnt = 0;
    do {
        cnt++;
        ss << str << "\n";
    } while (next_permutation(str.begin(), str.end()));

    cout << cnt << "\n" << ss.str() << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
