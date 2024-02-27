#include <iostream>

using namespace std;

int main() {

    int n, m, k;

    cin >> n >> m >> k;

    if (n + m > k && n + k > m && m + k > n) {
        cout << "yes" << "\n";
    }
    else {
        cout << "no" << "\n";
    }

    return 0;

}
