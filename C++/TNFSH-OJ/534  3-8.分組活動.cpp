#include <iostream>

using namespace std;

int main() {

    int n, m;
    
    cin >> n >> m;

    if (n % 2 == m % 2) {
        cout << "yes" << "\n";
    }
    else {
        cout << "no" << "\n";
    }

    return 0;

}
