#include <iostream>
#define int long long
#define ln "\n"

using namespace std;
 
signed main() {

    int n;
    cin >> n;

    int ans = 1;
    while (n != 1) {
        ans += n;
        if (n % 2) {
            n = 3 * n + 1;
        }
        else {
            n = n / 2;
        }
    }

    cout << (ans) << ln;

    return 0;

}

