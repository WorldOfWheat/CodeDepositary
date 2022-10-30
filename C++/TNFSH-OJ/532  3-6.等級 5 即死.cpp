#include <iostream>

using namespace std;

int main() {

    int n, m;
    
    cin >> n >> m;

    int ans = 0, ans2 = 0;
    
    if (n % 2 == 0) {
        ans++;
    }
    if (n % 3 == 0) {
        ans2++;
    }

    if (m % 2 == 0) {
        ans++;
    }
    if (m % 3 == 0) {
        ans2++;
    }

    cout << ans << " " << ans2 << "\n";

    return 0;

}
