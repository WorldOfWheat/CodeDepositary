#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<double>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; x++)
#define rep2(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

vv ve(7, vector<double>(4));

void solve() {

    rep (i, 0, 7) {
        int sum = 0;
        rep (j, 0, 4) {
            cin >> ve[i][j];
        }
    }

    double maxi = -1e18;
    int day;
    rep (i, 0, 7) {
        int sum = 0;
        rep (j, 0, 4) {
            sum += ve[i][j];
        }
        if (maxi < sum) {
            day = i + 1;
            maxi = sum;
        }
    }
    cout << day << ln;

    double maxi2 = -1e18;
    int _time;
    rep (i, 0, 4) {
        int sum = 0;
        rep (j, 0, 7) {
            sum += ve[j][i];
        }
        if (maxi2 < sum) {
            _time = i;
            maxi2 = sum;
        }
    }
    switch (_time) {
        case 0:
            cout << "morning" << ln;
            break;

        case 1:
            cout << "afternoon" << ln;
            break;

        case 2:
            cout << "night" << ln;
            break;

        case 3:
            cout << "early morning" << ln;
            break;
    }

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
