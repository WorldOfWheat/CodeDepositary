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

const vector<string> items = {"Pen", "Pineapple", "Apple", "Pineapple pen"};

void solve() {
    int n;
    cin >> n;
    string now;
    int cnt = 0;
    int cnt2 = 1;
    int cnt3 = 0;
    int cnt4 = 0;
    rep (i, 0, n) {
        if (cnt == cnt2) {
            cnt = 0;
            cnt3++;
            cnt3 %= 4;
            cnt4++;
        }
        cnt++;
        now = items[cnt3];
        if (cnt4 == 4) {
            cnt4 = 0;
            cnt2++;
        }
    }
    cout << now << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
