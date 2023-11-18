#include <iostream>
#define ln "\n"

using namespace std;
 
int main() {

    int t;
    cin >> t;

    while (t--) {
        int ans = 1;

        int a;
        cin >> a;

        for (int i = 1; i <= a; i++) {
            ans *= i;
        }

        cout << (ans % 10) << ln;
    }

    return 0;

}

