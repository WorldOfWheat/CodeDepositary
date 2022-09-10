#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define F first
#define S second

using namespace std;

int n;

void solve () {

    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        string str;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j) ) {
                str += "1";
            }
            else {
                str += "0";
            }
        }
        str += "0";
        stringstream ss;
        for (int j = n; j >= 1; j--) {
            bool gray = (str[j] - '0') ^ (str[j-1] - '0');
            ss << gray;
        }
        cout << (ss.str()) << "\n";
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
