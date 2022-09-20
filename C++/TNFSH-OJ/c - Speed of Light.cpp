#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

void solve() {

    cout << "1 Light-second(LS) is " << (299792458ll) << " metres." << "\n";
    cout << "1 Light-minute(LM) is " << (299792458ll*60) << " metres." << "\n";
    cout << "1 Light-hour(LH) is " << (299792458ll*60*60) << " metres." << "\n";
    cout << "1 Light-day(LD) is " << (299792458ll*60*60*24) << " metres." << "\n";
    cout << "1 Light-week(LW) is " << (299792458ll*60*60*24*7) << " metres." << "\n";
    cout << "1 Light-year(LY) is " << (299792458ll*60*60*24*365) << " metres." << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
