#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define N 50000+1

using namespace std;

multiset<string> ms;
multiset<string> ms2;

void solve() {
    int n, m;
    cin >> n >> m;
    bitset<26> mask = (1 << (n)) - 1;
    rep (i, 0, m) {
        bitset<26> bs;
        string str;
        cin >> str;
        for (auto i : str) {
            bs[i -'A'] = 1;
        }
        str = bs.to_string();
        ms.insert(str);
        bs ^= mask;
        ms2.insert(bs.to_string());
    }
    int ans = 0;
    for (auto i : ms2) {
        ans += ms.count(i);
    }
    cout << (ans/2) << ln;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
