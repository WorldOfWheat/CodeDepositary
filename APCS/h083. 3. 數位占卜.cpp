#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<string> s;
    int n;
    cin >> n;
    while (n--) {
        string a;
        cin >> a;
        s.insert(a);
    }
    int ans = 0;
    for (auto a : s) {
        if (a.length() < 3) continue;
        int l = a.length();
        for (int i = 0; i < l/2; i++) {
            if ( a.substr(0, i+1) == a.substr(l-1-i, l) ) {
                if (s.count(a.substr(i+1, (l-i-1)-(i+1)))) ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
