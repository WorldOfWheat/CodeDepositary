#include <iostream>

using namespace std;
 
int main() {

    int n, m;

    cin >> n >> m;

    // 2b = x - y
    // b = (x - y) / 2
    // a = x - b;

    int b = (n - m) / 2;
    int a = n - b;

    cout << "a: " << a << ", b: " << b << "\n";

    return 0;

}