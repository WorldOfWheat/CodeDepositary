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
#define INF (LLONG_MAX - 1)

using namespace std;

V ve;

int dfs(int l, int r) {

    if (l >= r) {
        return ve[l];
    }

    int mid = (l + r) / 2;  
    
    int res = max(dfs(l, mid), dfs(mid + 1, r));

    int ptrl = mid;
    int ptrr = mid;
    int now = ve[mid];
    while (ptrl >= l || ptrr <= r) {
        if (ptrl < l) {
            now = ve[ptrr]; 
        }
        else if (ptrr > r) {
            now = ve[ptrl];
        }
        else {
            now = max(ve[ptrl], ve[ptrr]);
        }

        while (ptrl >= l && ve[ptrl] >= now) {
            ptrl--;
        }
        while (ptrr <= r && ve[ptrr] >= now) {
            ptrr++;
        }

        res = max(res, (ptrr - ptrl - 1) * now);
    }

    return res;
    
}

void solve() {
	
    int n;
    cin >> n;

    ve.resize(n);
    rep (i, 0, n) {
        cin >> ve[i];
    }

    cout << (dfs(0, n-1)) << ln;

}

signed main() {
    
	ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}
