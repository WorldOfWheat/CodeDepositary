#include <iostream>

using namespace std;

int main() {

    int n, m, o, p;

    cin >> n >> m >> o >> p;

    if ((n <= o && o <= m) || (n <= p && p <= m) || (o <= n && m <= p)) {
        cout << "yes" << "\n";
    }
    else {
        cout << "no" << "\n";
    }

    return 0;

}
