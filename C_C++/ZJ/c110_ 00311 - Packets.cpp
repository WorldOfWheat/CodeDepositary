#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int input[6];
    while (true) {
        for (auto &a : input) cin >> a;
        bool stop = true;
        for (auto a : input) if (a) stop = false;
        if (stop) break;

        int ans = 0;
        ans += input[5];

        ans += input[4];
        input[0] -= input[4]*(36-25);

        ans += input[3];
        input[1] -= input[3]*5;

        ans += input[2]/4;
        ans += (input[2]%4 > 0);
        switch (input[2]%4) {
            case 1:
                input[1] -= 5;
                input[0] -= 7;
                break;
            case 2:
                input[1] -= 3;
                input[0] -= 6;
                break;
            case 3:
                input[1] -= 1;
                input[0] -= 5;
                break;
        }

        if (input[1] > 0) {
            ans += input[1] / 9;
            if (input[1]%9) ans++;
            input[0] -= 36-(input[1]%9)*4;
        } else
        if (input[1] < 0) {
            input[0] -= abs(input[1])*4;
        }

        if (input[0] > 0) {
            ans += input[0] / 36;
            ans += (input[0] % 36 > 0);
        }

        cout << ans << endl;
    }

    return 0;
}
