#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "

using namespace std;

V ve;
multiset<int> ms;

void solve() {
    int n, m;
    cin >> n >> m;
    ve.resize(n+1);
    rep2 (i, 1, n) {
       cin >> ve[i];
    }
    rep2 (i, 1, m) {
        ms.insert(ve[i]);
    }
    int ans = 0;
    rep2 (i, m+1, n) {
        ans = max(ans, (*(ms.rbegin())) - (*(ms.begin())) );
        ms.insert(ve[i]);
        ms.erase(ms.find(ve[i-m]));
    }
    ans = max(ans, (*(ms.rbegin())) - (*(ms.begin())) );
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VP vector<pii>
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define INF (int) 1e18

using namespace std;

V ve;
deque<int>  de;
deque<int>  de2;

void solve() {
	
	int n, m;
	cin >> n >> m;

	ve.resize(n);

	rep (i, 0, n) {
		cin >> ve[i];
	}

	int ans = -INF;

	rep (i, 0, n) {
		int top = ve[i];
		
		while (de.size() && top > ve[de.back()]) {
			de.pop_back();
		}
		while (de2.size() && top < ve[de2.back()]) {
			de2.pop_back();
		}
		
		de.push_back(i);
		de2.push_back(i);

		while (de.size() && de.front() <= i - m) {
			de.pop_front();
		}
		while (de2.size() && de2.front() <= i - m) {
			de2.pop_front();
		}

		ans = max(ans, ve[de.front()] - ve[de2.front()]);
	}

	cout << ans << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}