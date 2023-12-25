#include <iostream>
using namespace std;

int main() {

    int a, b, c, n;

    cin >> a >> b >> c >> n;

    bool flag = true;

    for (int i = 0; i <= n; i++) {
        if (a * i > n) {
            break;
        }
        for (int j = 0; j <= n; j++) {
            if (a * i + b * j > n) {
                break;
            }
            for (int k = 0; k <= n; k++) {
                if (a * i + b * j + c * k > n) {
                    break;
                }
                if ((a * i + b * j + c * k) == n) {
                    flag = false;
                    cout << i << " " << j << " " << k << "\n";
                }
            }
        }
    }

    if (flag) {
        cout << "impossible" << "\n";
    }

    return 0;
}
