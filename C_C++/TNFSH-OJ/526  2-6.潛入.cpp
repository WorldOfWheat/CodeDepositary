#include <iostream>

using namespace std;

int main() {

    int n;
    
    cin >> n;

    int ans = 0;

    ans += n % 10;
    ans *= 10;

    ans += n % 100 / 10;
    ans *= 10;

    ans += n % 1000 / 100;

    cout << ans << "\n";

    return 0;

}
