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

vector<bitset<10>> ve(10);

void solve() {
    int n, m;
    cin >> n >> m;
    rep (i, 0, n) {
        rep (j, 0, m) {
            bool a;
            cin >> a;
            ve[i][j] = a;
        }
    }
    bitset<10> _and = ve[0];
    bitset<10> _or = ve[0];
    bitset<10> _xor = ve[0];
    rep (i, 1, n) {
        _and &= ve[i];
        _or |= ve[i];
        _xor ^= ve[i];
    }
    cout << "AND: ";
    rep (i, 0, m) {
        cout << (_and[i]) << sp;
    }
    cout << ln;
    cout << " OR: ";
    rep (i, 0, m) {
        cout << (_or[i]) << sp;
    }
    cout << ln;
    cout << "XOR: ";
    rep (i, 0, m) {
        cout << (_xor[i]) << sp;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
