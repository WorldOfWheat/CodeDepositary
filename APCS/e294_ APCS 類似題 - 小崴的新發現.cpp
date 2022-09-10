#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

string str;

void solve() {

    int len = str.length();
    vector<int> low;
    vector<int> high;
    for (int i = 0; i < len; i++) {
        int top = (str[i] - '0');
        if ( top % 2 ) {
            low.push_back(top);
            high.push_back(top);
            continue;
        }
        high.push_back(top+1);
        low.push_back(top-1);
        if (low[i] <= 0) {
            for (int j = i-1; j >= 1; j--) {
                if (low[j] <= 0) {
                    low[j] = 9;
                    low[j-1]--;
                }
                else if (low[j] % 2) {
                    low[j]-=2;
                    if (low[j] <= 0) {
                        low[j] = 9;
                        low[j-1]--;
                    }
                    break;
                }
                else {
                    low[j]--;
                    break;
                }
            }
        }
        for (int j = i+1; j < len; j++) {
            high.push_back(1);
            low.push_back(9);
        }
        break;
    }
    int sum = 0;
    int k = 1;
    for (auto it = high.rbegin(); it != high.rend(); it++) {
        sum += k*(*it);
        k*=10;
    }
    int sum2 = 0;
    k = 1;
    for (auto it = low.rbegin(); it != low.rend(); it++) {
        sum2 += k*(*it);
        k*=10;
    }
    int num = 0;
    k = 1;
    for (auto it = str.rbegin(); it != str.rend(); it++) {
        num += k*((*it) - '0');
        k*=10;
    }
    cout << ( min(
    abs(num - sum),
    abs(num - sum2)
    ) ) << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> str) solve();

    return 0;
}

