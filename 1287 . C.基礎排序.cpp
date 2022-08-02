#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

int n;
vector<int> ve;

void merge_sort(int l, int r, vector<int> &x) {

    if (l == r) return;

    int mid = (l + r) / 2;
    merge_sort(l, mid, x);
    merge_sort(mid+1, r, x);

    int ptr_l = l;
    int ptr_r = mid + 1;
    vector<int> result;

    while (ptr_l <= mid && ptr_r <= r) {
        if ( x[ptr_l] < x[ptr_r]) {
            result.push_back(x[ptr_l]);
            ptr_l++;
        }
        else {
            result.push_back(x[ptr_r]);
            ptr_r++;
        }
    }

    while (ptr_l <= mid) {
        result.push_back(x[ptr_l]);
        ptr_l++;
    }
    while (ptr_r <= r) {
        result.push_back(x[ptr_r]);
        ptr_r++;
    }
    for (int i = 0; i < result.size(); i++) {
        x[i+l] = result[i];
    }

    return;
}

void solve() {

    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    merge_sort(0, ve.size() - 1, ve);
    for (auto a : ve) {
        cout << a << " ";
    }
    cout << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
