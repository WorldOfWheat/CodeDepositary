#include <iostream>

using namespace std;
 
int main() {

    int a, b, n;

    cin >> a >> b >> n;

    for (int i = 1; i <= n; i++) {
        if (i % a == 0 && i % b == 0) {
            cout << "FizzBuzz";
        }
        else if (i % a == 0) {
            cout << "Fizz";
        }
        else if (i % b == 0) {
            cout << "Buzz";
        }
        else {
            cout << i;
        }

        cout << "\n";
    }

    return 0;

}
