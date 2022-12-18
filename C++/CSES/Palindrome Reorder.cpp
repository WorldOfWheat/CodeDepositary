#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y, z) for(int x = y; x < z; x++)
#define rep2(x, y, z) for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define INF (int) 1e18

using namespace std;

string str;
map<char, int> ma;

void solve() {

    cin >> str;

    int len = str.length();
    rep (i, 0, len) {
        ma[str[i]]++;
    }
  
    int isOdd = 0;
    for (auto i : ma) {
        if (i.S % 2 != 0) {
            isOdd++;
        }
    }
    if (isOdd >= 2) {
        cout << "NO SOLUTION" << '\n';
        return;
    }

    string temp = "";
    string temp2 = "";
    string mid = "";
    for (auto i : ma) {
        if (i.S % 2 != 0) {
            rep (j, 0, i.S) {
                mid += i.F;
            }
            continue;
        }
        rep (j, 0, i.S / 2) {
            temp += i.F;
            temp2 += i.F;
        }
    }

    reverse(temp2.begin(), temp2.end());

    cout << (temp + mid + temp2) << '\n';

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;

}
