#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    /*for (auto a : v) {
        cerr << a << " ";
    }
    cerr << "\n";*/
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            int a = v[i]+v[j];
            auto it = lower_bound(v.begin(), v.end(), a);
            ans += (n-1-i) - distance(it, v.end());
            ////cerr << (n-1-i) - distance(it, v.end()) << "\n";
        }
    }
    cout << ans << endl;

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (v[i] + v[j] > v[k]) ans++;
            }
        }
    }
    cout << ans << endl;
    /*
    for (auto a : v) {
        cerr << a << " ";
    }
    cerr << "\n";
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            int a = v[i]+v[j];
            auto it = lower_bound(v.begin(), v.end(), a);
            ans += (n-1-i) - distance(it, v.end());
            //cerr << distance(it, v.end()) << endl;
            cerr << (n-1-i) << " " << distance(it, v.end()) << "\n";
        }
    }
    cout << ans << endl;
*/
    return 0;
}

