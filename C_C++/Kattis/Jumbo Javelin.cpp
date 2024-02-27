#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;

        sum += in;
    }

    cout << (sum - (n - 1)) << "\n";

    return 0;

}