#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n;
vector<int> ve(4);

void solve() {

    ve[0] = n;
    for (int i = 1; i < 4; i++) {
        int a;
        cin >> a;
        ve[i] = a;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> ve_backup = ve;
        vector<int> ve2(4);
        int A = 0;
        int B = 0;
        for (int i = 0; i < 4; i++) {
            cin >> ve2[i];
            if (ve[i] == ve2[i]) {
                A++;
                ve[i] = -1;
                ve2[i] = -1;
            }
        }
        sort(ve.begin(), ve.end());
        sort(ve2.begin(), ve2.end());
        bool flag[4+1] = {0};
        for (auto it = upper_bound(ve2.begin(), ve2.end(), -1); it != ve2.end(); it++) {
            if (binary_search(ve.begin(), ve.end(), *it)) {
                auto it2 = lower_bound(ve.begin(), ve.end(), *it);
                *it2 = -1;
                B++;
            }
        }
        cout << A << "A" << B << "B" << ln;
        ve = ve_backup;
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
