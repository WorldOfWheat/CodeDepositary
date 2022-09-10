#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

const string letters = "abcdefghijk";
int n;

void solve() {

    string str = letters.substr(0, n);
    do {
        cout << str << ln;
    } while (next_permutation(str.begin(), str.end()));

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n, n) solve();

    return 0;
}
