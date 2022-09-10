#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const string key = "mjqhofawcpnsexdkvgtzblryui";
const string key2 = "uzrmatifxopnhwvbslekycqjgd";
int n, m;
map<int, int> mp;

void init() {
    for (int i = 1; i <= 26; i++) {
        mp[(int) key2[i-1]] = i;
        mp[i] = (int) key[i-1];
    }
}

void solve() {

    cin >> m;
    string str;
    cin >> str;
    bool flag = isalpha(str[0]);
    int ans = 0;
    stringstream ss;
    for (int i = 0; i < m; i++) {
        if (i != 0) {
            cin >> str;
        }
        if (flag) {
            char a = str[0];
            ans += mp[(int) a];
        }
        else {
            int a = atoi(str.c_str());
            ss << ((char) mp[a]);
        }
    }
    if (flag) {
        cout << ans << "\n";
    }
    else {
        cout << ss.str() << "\n";
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    cin >> n;
    while (n--) solve();

    return 0;
}
