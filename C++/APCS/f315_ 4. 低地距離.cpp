#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

class seg_tree {
    public:
        seg_tree(int x) {
            data.resize(4*x);
            _size = x;
        }
        void build(vector<int> x) {
            _size = x.size();
            input.resize(_size);
            copy(x.begin(), x.end(), input.begin());
            build(1, _size, 1);
        }
        void update(int x) {
            update(x, 1, 1, _size);
        }
        int query(int x) {
            query(x, x);
        }
        int query(int l, int r) {
            return query(l, r, 1, _size, 1);
        }
    private:
        vector<int> input;
        vector<int> data;
        int _size;
        int lc(int x) {
            return (x*2);
        }
        int rc(int x) {
            return (x*2+1);
        }
        void build(int l, int r, int x) {
            if (l == r) {
                data[x] = input[l];
                return;
            }
            int mid = (l + r) / 2;
            build(l, mid, lc(x));
            build(mid+1, r, rc(x));
            data[x] = data[lc(x)] + data[rc(x)];
        }
        void update(int x, int y, int l, int r) {
            //cout << x << " " << y << " " << l << " " << r <<endl;
            if (l == r) {
                data[y] = 1;
                return;
            }
            int mid = (l + r) / 2;
            if (x <= mid) {
                update(x, lc(y), l, mid);
            } else {
                update(x, rc(y), mid+1, r);
            }
            data[y] = data[lc(y)] + data[rc(y)];
        }
        int query(int l, int r, int l2, int r2, int x) {
            if (l == l2 && r == r2) {
                return data[x];
            }
            int sum = 0;
            int mid = (l2 + r2) / 2;
            if (r <= mid) {
                sum += query(l, r, l2, mid, lc(x));
            }
            else if (l > mid) {
                sum += query(l, r, mid+1, r2, rc(x));
            }
            else {
                int a = query(l, mid, l2, mid, lc(x));
                int b = query(mid+1, r, mid+1, r2, rc(x));
                sum += a + b;
            }
            return sum;
        }
};

vector<int> ve;
vector<pii> ve2;

void solve() {

    int n;
    cin >> n;
    seg_tree seg(2*n);
    ve2.resize(2*n);
    ve.push_back(0);
    ve2.push_back(mp(0, 0));
    for (int i = 1; i <= 2*n; i++) {
        int a;
        cin >> a;
        //cout << (ve2[a].F) << endl;
        if (ve2[a].F == 0) {
            ve2[a].F = i;
        } else {
            ve2[a].S = i;
        }
        ve.push_back(a);
    }
    //seg.build(ve);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += seg.query(ve2[i].F, ve2[i].S);
        seg.update(ve2[i].F);
        seg.update(ve2[i].S);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
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

int n;
VP ve;
V vis;
int ans = 0;

int dfs(int l, int r) {

	if (l >= r) {
		return 0;
	}

	int mid = (l + r) / 2;
	int res = dfs(l, mid) + dfs(mid + 1, r);

	VP temp;
	int l2 = l;
	int r2 = mid + 1;
	while (l2 <= mid && r2 <= r) {
		if (ve[l2].F < ve[r2].F) {
			temp.push_back(ve[l2]);
			l2++;
		}
		else {
			res += (l2 - l) * ve[r2].S;
			temp.push_back(ve[r2]);
			r2++;
		}
	}
	while (l2 <= mid) {
		temp.push_back(ve[l2]);
		l2++;
	}
	while (r2 <= r) {
		res += (l2 - l) * ve[r2].S;
		temp.push_back(ve[r2]);
		r2++;
	}

	rep2 (i, l, r) {
		ve[i] = temp[i-l];
	}

	return res;

}

void solve() {

	cin >> n;
	n *= 2;

	ve.resize(n);
	vis.resize(n);

	rep (i, 0, n) {
		int a;
		cin >> a;

		if (vis[a]) {
			ve[i] = {a, -1};	
		}
		else {
			ve[i] = {a, 1};
			vis[a] = true;
		}
	}

	cout << abs(dfs(0, n - 1)) << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
	
}