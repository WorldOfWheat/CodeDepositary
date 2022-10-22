#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n, m;
vector<int> ve;
vector<int> ve_order;

class BIT_tree {
    public:
        BIT_tree(int x) {
            _size = x + 1;
            data.resize(_size);
        }
        void update(int pos, int value) {
            for (int i = pos; i <=_size; i+=getLowbit(i)) {
                data[i] += value;
            }
        }
        int query(int pos) {
            int result = 0;
            for (int i = pos; i >= 1; i-=getLowbit(i)) {
                result += data[i];
            }
            return (result);
        }
    private:
        vector<int> data;
        int _size;
        int getLowbit(int x) {
            return (x & -x);
        }
};

void solve() {

    cin >> n >> m;

    BIT_tree bit(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bit.update(a, c);
        bit.update(b+1, -c);
    }

    ve_order.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve_order[i];
    }
    sort(ve_order.begin(), ve_order.end());

    for (int i = 1; i <= n; i++) {
        int a = bit.query(i);
        if (a != 0) ve.push_back(a);
    }
    sort(ve.rbegin(), ve.rend());
    int ans = 0;
    for (int i = 0; i < ve.size(); i++) {
        ans += ve_order[i] * ve[i];
    }
    cout << ans << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;

int n, m;
vector<int> ve;
vector<int> ve_order;

struct node{
    int lc;
    int rc;
    int tag;
    int sum;
};

class seg_tree {
    public:
        seg_tree(int x) {
            _size = x;
            data.resize(_size << 2);
            build(1, _size, 1);
        }
        node query(int l, int r) {
            return query(l, r, 1, _size, 1);
        }
        void update(int l, int r, int value) {
            update(l, r, 1, _size, value, 1);
        }
    private:
        int _size;
        vector<node> data;
        void pull(node &x, node y, node z) {
            x.sum = y.sum + z.sum;
        }
        void push(int l, int r, int x) {
            node &left = data[data[x].lc];
            node &right = data[data[x].rc];
            int mid = (l + r) >> 1;
            left.sum += (mid - l + 1) * data[x].tag;
            right.sum += (r - mid) * data[x].tag;
            left.tag += data[x].tag;
            right.tag += data[x].tag;
            data[x].tag = 0;
        }
        void build(int l, int r, int x) {
            if (l == r) {
                data[x].sum = 0;
                return;
            }
            data[x].lc = (x << 1);
            data[x].rc = (x << 1) | 1;
            int mid = (l + r) >> 1;
            build(l, mid, data[x].lc);
            build(mid+1, r, data[x].rc);
            pull(data[x], data[data[x].lc], data[data[x].rc]);
        }
        node query(int l, int r, int l2, int r2, int x) {
            if (l == l2 && r == r2) {
                return data[x];
            }
            push(l2, r2, x);
            int mid = (l2 + r2) >> 1;
            if (r <= mid) {
                return query(l, r, l2, mid, data[x].lc);
            }
            else if (l > mid) {
                return query(l, r, mid+1, r2, data[x].rc);
            }
            else {
                node result;
                pull(result, query(l, mid, l2, mid, data[x].lc), query(mid+1, r, mid+1, r2, data[x].rc) );
                return result;
            }
        }
        void update(int l, int r, int l2, int r2, int value, int x) {
            if (l == l2 && r == r2) {
                data[x].sum += (r - l + 1) * value;
                data[x].tag += value;
                return;
            }
            push(l2, r2, x);
            int mid = (l2 + r2) >> 1;
            if (r <= mid) {
                update(l, r, l2, mid, value, data[x].lc);
            }
            else if (l > mid) {
                update(l, r, mid+1, r2, value, data[x].rc);
            }
            else {
                update(l, mid, l2, mid, value, data[x].lc);
                update(mid+1, r, mid+1, r2, value, data[x].rc);
            }
            pull(data[x], data[data[x].lc], data[data[x].rc]);
        }
};

void solve() {

    cin >> n >> m;

    seg_tree seg(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        seg.update(a, b, c);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ve_order.push_back(a);
        int b = seg.query(i+1, i+1).sum;
        if (b != 0) ve.push_back(b);
    }
    sort(ve_order.begin(), ve_order.end());
    sort(ve.rbegin(), ve.rend());
    int ans = 0;
    for (int i = 0; i < ve.size(); i++) {
        ans += ve_order[i] * ve[i];
    }
    cout << ans << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
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

int n, m;
V ve;
V line;

void solve() {

    cin >> n >> m;

    line.resize(n);
    ve.resize(n);

    rep2 (i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        line[a] += c;
        line[b + 1] += -c;
    }

    int now = 0;
    rep (i, 0, n) {
        now += line[i];
        line[i] = now;
    }
    sort(line.rbegin(), line.rend());

    rep (i, 0, n) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());

    int ans = 0;
    rep (i, 0, n) {
        ans += ((*(next(ve.begin(), i))) * (*(next(line.begin(), i))));
    }

    cout << ans << ln;

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;

}
