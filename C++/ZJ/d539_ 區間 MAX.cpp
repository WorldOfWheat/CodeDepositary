#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second

using namespace std;
__attribute__((optimize("-O3")))

struct node{
    int left;
    int right;
    int lc;
    int rc;
    int sum;
    int maxi;
};

class seg_tree {
    public:
        seg_tree(vector<int> x) {
            _size = x.size();
            input.assign(x.begin(), x.end());
            data.resize(4*_size);
            build(1, _size, 1);
        }
        node query(int l, int r) {
            return query(l, r, 1, _size, 1);
        }
    private:
        int _size;
        vector<int> input;
        vector<node> data;
        int getLc(int x) {
            return x << 1;
        }
        int getRc(int x) {
            return (x << 1) + 1;
        }
        void pull(node &x, node y, node z) {
            x.left = y.left;
            x.right = z.right;
            x.sum = y.sum + z.sum;
            x.maxi = max(y.maxi, z.maxi);
        }
        void build(int l, int r, int x) {
            if (l == r) {
                data[x].left = data[x].right = data[x].lc = data[x].rc = l;
                data[x].sum = input[l-1];
                data[x].maxi = input[l-1];
                return;
            }
            int mid = (l + r) / 2;
            build(l, mid, getLc(x));
            build(mid+1, r, getRc(x));
            data[x].lc = getLc(x);
            data[x].rc = getRc(x);
            pull(data[x], data[ data[x].lc ], data[ data[x].rc ]);
        }
        node query(int l, int r, int l2, int r2, int x) {
            if (l == l2 && r == r2) {
                return data[x];
            }
            int mid = (l2 + r2) >> 1;
            if (r <= mid) {
                return query(l, r, l2, mid, getLc(x));
            }
            else if (l > mid) {
                return query(l, r, mid+1, r2, getRc(x));
            }
            else {
                node a = query(l, mid, l2, mid, getLc(x));
                node b = query(mid+1, r, mid+1, r2, getRc(x));
                node result;
                pull(result, a, b);
                return result;
            }
        }
};

int n, m;
vector<int> ve;

void solve() {

    ve.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    seg_tree seg(ve);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << (seg.query( min(a, b), max(a, b) ).maxi) << "\n";
    }

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) solve();

    return 0;
}
