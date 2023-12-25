#include <iostream>
#define int long long
#define ln "\n"

using namespace std;
 
signed main() {

    int n;
    cin >> n;

    if (n % 2) {
        cout << "still running" << ln;
        return 0;
    }

    int ans = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (i % 2) {
            last = a;
        }
        else {
            ans += a - last;
        }
    }

    cout << (last - ans) << ln;

    return 0;

}

