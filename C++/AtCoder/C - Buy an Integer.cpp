#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, k;

bool test(int x) {
    int price = n * x + m * ((int) log10(x) + 1);
    return price <= k;
}

int binarySearch(int left, int right) {
    int result = 0;
    for (int i = (right - left) >> 1; i > 0; i >>= 1) {
        while (test(result + i)) {
            result += i;
        }
    }

    return result;
}

void solve() {
    cin >> n >> m >> k;   

    cout << (min((int) 1e9, binarySearch(0, 1e9 + 1))) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
