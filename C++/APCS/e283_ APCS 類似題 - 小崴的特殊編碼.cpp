#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n;

void solve() {

    stringstream ss;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = (a*8) + (b*4) + (c*2) + (d*1);
        switch (sum) {
            case 5:
                ss << "A";
                break;

            case 7:
                ss << "B";
                break;

            case 2:
                ss << "C";
                break;

            case 13:
                ss << "D";
                break;

            case 8:
                ss << "E";
                break;

            case 12:
                ss << "F";
                break;
        }
    }
    cout << ss.str() << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}

