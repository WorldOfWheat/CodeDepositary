#include <bits/stdc++.h>

using namespace std;

vector<string> arr;
vector<string> arr_rotated;

void solve() {
    int n, m;
    while(true) {
        arr.clear();
        arr_rotated.clear();

        cin >> n >> m;
        if (n == 0 || m == 0) {
            return;
        }

        arr.resize(n);
        arr_rotated.resize(m);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                arr_rotated[j] += arr[i][j];
            }
        }
        
        sort(arr_rotated.begin(), arr_rotated.end(), [](string x, string y) {
            for (int i = 0; i < x.length(); i++) {
                char x_lower = tolower(x[i]);
                char y_lower = tolower(y[i]);
                if (x_lower == y_lower) {
                    continue;
                }
                return x_lower < y_lower;
            }
            return false;
        });

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                cout << arr_rotated[i][j];
            }
            cout << '\n';
        }
    }
}

int main() {
    solve();

    return 0;
}
