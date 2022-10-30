#include <iostream>
#define int long long
#define ln "\n"

using namespace std;
 
signed main() {

    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;
    int now = 0;
    while (true) {
        now += n;
        ans++;
        if (now >= k) {
            cout << ans << ln;
            return 0;
        }
        now -= m;
    }

    return 0;

}

