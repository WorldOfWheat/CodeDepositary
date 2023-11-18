#include <iostream>

using namespace std;
 
int main() {

    int t;

    cin >> t;

    while (t--) {
        int a, b;

        cin >> a >> b;

        int k = a;

        for (int i = 0; i < b-1; i++) {
            a *= k;
        }

        cout << a << "\n";
    }

    return 0;

}
