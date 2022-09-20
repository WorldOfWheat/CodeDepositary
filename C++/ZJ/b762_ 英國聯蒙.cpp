#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n;

void solve() {

    cin >> n;
    int kill = 0, assist = 0, die = 0;
    int kill_cont = 0;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        str.erase(str.find_last_not_of(" ") + 1);
        switch (str.back()) {
            case 'l':
                kill_cont++;
                kill++;
                switch (kill_cont) {
                    case 3:
                        cout << "KILLING SPREE!" << ln;
                        break;

                    case 4:
                        cout << "RAMPAGE~" << ln;
                        break;

                    case 5:
                        cout << "UNSTOPPABLE!" << ln;
                        break;

                    case 6:
                        cout << "DOMINATING!" << ln;
                        break;

                    case 7:
                        cout << "GUALIKE!" << ln;
                        break;

                    default:
                        if (kill_cont >= 8) {
                            cout << "LEGENDARY!" << ln;
                        }
                        else {
                            cout << "You have slain an enemie." << ln;
                        }
                        break;
                }

                break;

            case 't':
                assist++;
                break;

            case 'e':
                die++;
                if (kill_cont < 3) {
                    cout << "You have been slained." << ln;
                }
                else if (kill_cont >= 3) {
                    cout << "SHUTDOWN." << ln;
                }
                kill_cont = 0;
                break;

        }
    }
    cout << kill << "/" << die << "/" << assist << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
