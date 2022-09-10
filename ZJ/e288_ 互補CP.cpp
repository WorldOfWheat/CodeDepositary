#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define sp " "
#define rep(x, y) for (int x = 0; x < y; x++)

using namespace std;

int n, m;
multiset<int> ms;
multiset<int> ms2;
unordered_map<int, int> ump;

void solve() {

    cin >> n >> m;
    bitset<40> mask = (1ll << n) - 1;
    int ans = 0;
    rep (i, m) {
        string str;
        cin >> str;
        bitset<40> bs;
        for (auto a : str) {
            if (isupper(a)) {
                bs[a - 'A'] = 1;
            }
            else {
                bs[(a - 'a') + 26] = 1;
            }
        }
        int temp = bs.to_ulong();
        bs ^= mask;
        ans += ump[bs.to_ulong()];
        ump[temp]++;
    }
    cout << ans << ln;

}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
