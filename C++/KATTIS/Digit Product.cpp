#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int cnt = 10;

    while (n >= 10) {
        int cnt = 10;
        int res = 1;
        while (n % cnt != n) {
            int k = (n % cnt / (cnt / 10));
            if (k != 0) {
                res *= k;
            }
            cnt *= 10;
        }
        int k = (n % cnt / (cnt / 10));
        if (k != 0) {
            res *= k;
        }        

        n = res;
    }

    cout << n << "\n";

    return 0;

}