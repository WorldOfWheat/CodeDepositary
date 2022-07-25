#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int maximum = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int a = i;
            int b = j;
            int c = n-a-b;
            if (c < 0) break;
            maximum = max(maximum, (2022+abs(b-c)+a*b+b*c+c*c-abs(b*b-a*a)) );
        }
    }
    cout << maximum << endl;

    return 0;
}
