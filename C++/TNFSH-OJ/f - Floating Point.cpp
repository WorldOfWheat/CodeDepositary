#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

double n, m;
char symbol;

void solve() {

    cin >> n >> symbol >> m;
    if (symbol == '/' && m == 0) {
        cout << "ERROR" << "\n";
        return;
    }
    cout << fixed << setprecision(4);
    cout << n << " " << symbol << " " << m << " = ";
    switch (symbol) {
        case '+':
            cout << (n + m) << "\n";
            break;
        case '-':
            cout << (n - m) << "\n";
            break;
        case '*':
            cout << (n * m) << "\n";
            break;
        case '/':
            cout << (n / m) << "\n";
            break;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
