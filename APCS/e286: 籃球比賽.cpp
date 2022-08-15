#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int sum;
int sum2;

void solve() {
        
    for (int i = 0; i < 4; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    for (int i = 0; i < 4; i++) {
       int a;
       cin >> a;
       sum2 += a;     
    }
    bool flag = sum > sum2;
    cout << sum << ":" << sum2 << ln;
    sum = sum2 = 0;
    for (int i = 0; i < 4; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    for (int i = 0; i < 4; i++) {
       int a;
       cin >> a;
       sum2 += a;     
    }
    bool flag2 = sum > sum2;
    cout << sum << ":" << sum2 << ln;
    if (flag && flag2) {
      cout << "Win" << ln;
    }
    else if (!flag && !flag2) {
      cout << "Lose" << ln;
    }
    else {
      cout << "Tie" << ln;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
