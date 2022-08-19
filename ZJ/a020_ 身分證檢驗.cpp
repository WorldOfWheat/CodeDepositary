#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

string str;
map<char, int> mp = {
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14},
    {'F', 15},
    {'G', 16},
    {'H', 17},
    {'I', 34},

    {'J', 18},
    {'K', 19},
    {'L', 20},
    {'M', 21},
    {'N', 22},
    {'O', 35},
    {'P', 23},
    {'Q', 24},
    {'R', 25},

    {'S', 26},
    {'T', 27},
    {'U', 28},
    {'V', 29},
    {'W', 32},
    {'X', 30},
    {'Y', 31},
    {'Z', 33}
};

void solve() {

    cin >> str;
    str = to_string(mp[str[0]]) + str.substr(1);
    int sum = str[0] - '0';
    for (int i = 1; i <= 9; i++) {
        sum += (str[i] - '0') * (9 - i + 1);
    }
    sum += str[10] - '0';
    cout << (sum % 10 ? "fake" : "real") << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
