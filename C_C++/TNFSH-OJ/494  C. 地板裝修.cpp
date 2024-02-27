#include <iostream>
using namespace std;

int main() {

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int o = 0; o < n; o++) {
                if (o % 2) {
                    for (int k = 0; k < m; k++) {
                        cout << (i % 2 ? "*" : " ");
                    }
                }
                else {
                    for (int k = 0; k < m; k++) {
                        cout << (i % 2 ? " " : "*");
                    }
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
