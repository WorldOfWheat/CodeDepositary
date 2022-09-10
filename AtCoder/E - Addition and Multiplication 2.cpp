#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n;
vector<int> ve(9);

void solve() {

    cin >> n;
    for (int i = 0; i < 9; i++) {
        cin >> ve[i];
    }

    int mini = *(min_element(ve.begin(), ve.end()));
    int len = n / mini;
    stringstream ss;
    for (int i = 0; i < len; i++) {
        for (int j = 9-1; j >= 0; j--) {
            if (1ll * mini * (len - i - 1) + ve[j] <= n) {
                n -= ve[j];
                ss << j+1;
                break;
            }
        }
    }
    cout << (ss.str()) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
