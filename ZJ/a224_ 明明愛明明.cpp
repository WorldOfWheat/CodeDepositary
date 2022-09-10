#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

string str;
map<char, ll> mp;

void solve() {

    mp.clear();
    for (int i = 0; i < str.length(); i++) {
        if (!isalpha(str[i])) continue;
        str[i] = tolower(str[i]);
        mp[str[i]]++;
    }
    int odd = 0, even = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if ((it->second) % 2 != 0) {
            odd++;
        }
        else {
            even++;
        }
    }
    cout << (odd > 1 ? "no..." : "yes !") << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> str) solve();

    return 0;
}
