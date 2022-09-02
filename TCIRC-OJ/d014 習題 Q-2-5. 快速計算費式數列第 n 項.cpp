#include <bits/stdc++.h>
#define int long long
#define vv vector<vector<int>>
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define M (int) 1e9 + 7

using namespace std;

int n;

vector<vector<int>> matrixMul(vector<vector<int>> x, vector<vector<int>> y) {
	int _size = x.size();
    vector<vector<int>> res(_size, vector<int>(_size));
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            int sum = 0;
			for (int o = 0; o < _size; o++) {
                sum += x[i][o] * y[o][j];
            }
            sum %= M;
            res[i][j] = sum;
        }
    }
    return res;
}

int qFib(int x) {
    vv mul = {
        {1, 1},
        {1, 0}
    };
    vv res = {
        {1, 1},
        {1, 0}
    };
    while (x > 0) {
        if (x & 1) {
            res = matrixMul(res, mul);
        }
        mul = matrixMul(mul, mul);
        x >>= 1;
    }
    return res[0][0];
}

void solve() {
    cout << (qFib(n-2)) << ln;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n, n != -1) solve();

    return 0;
}
