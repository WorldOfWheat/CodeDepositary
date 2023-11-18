#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n;
queue<int> qu;

void solve() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        int oper;
        cin >> oper;
        switch (oper) {
            case 1:
                int a;
                cin >> a;
                qu.push(a);
                break;

            case 2:
                if (qu.empty()) {
                    cout << -1 << ln;
                    break;
                }
                cout << qu.front() << ln;
                break;

            case 3:
                if (qu.size()) {
                    qu.pop();
                }
                break;
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
