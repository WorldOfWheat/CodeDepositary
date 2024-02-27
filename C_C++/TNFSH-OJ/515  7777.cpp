#include <iostream>

using namespace std;

int main() {

    int n;

    cin >> n;

    if ((1000 <= n && n <= 9999) && ((n % 1111 == 0))) {
        cout << "GREAT!!" << "\n";
    }
    else {
        cout << "OAQ" << "\n";
    }

    return 0;

}
