#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define db(x) cout << x << endl
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

multiset<int> ms;
int table[(int) 1e6];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1 ; i <= 100 ; i++) {
        for (int j = 1 ; j <= 100 ; j++) {
            for (int k = 1 ; k <= 100 ; k++) {
                table[i+j+k]++;
                table[i*j+k]++;
                table[i+j*k]++;
                table[i*j*k]++;
            }
        }
    }
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        cout << table[m] << "\n";
    }


    return 0;
}
 
