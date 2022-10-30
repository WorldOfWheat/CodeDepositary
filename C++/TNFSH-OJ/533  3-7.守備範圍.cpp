#include <iostream>

using namespace std;

int main() {

    int n, m, k;
    
    cin >> n >> m >> k;

    if (n <= k && k <= m) {
        cout << "yes" << "\n";
    }
    else {
        cout << "no" << "\n";
    }

    return 0;

}
