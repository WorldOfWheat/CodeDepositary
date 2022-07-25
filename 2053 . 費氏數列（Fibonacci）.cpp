#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>
#define mp(x, y) make_pair(x, y)
#define F first
#define S second
#define vector2d vector<vector<int>>

using namespace std;
__attribute__((optimize("-O3")))

int n, m, o, p, q;

vector2d matrixMultiply(vector2d x, vector2d y) {

    vector2d ans(2+1, vector<int>(2+1));
    int a = x[1][1] ;
    int b = x[1][2] ;
    int c = x[2][1] ;
    int d = x[2][2] ;

    int e = y[1][1] ;
    int f = y[1][2] ;
    int g = y[2][1] ;
    int h = y[2][2] ;

    ans[1][1] = (a*e + b*g) % ((int) 1e9+7);
    ans[1][2] = (a*f + b*h) % ((int) 1e9+7);
    ans[2][1] = (c*e + d*g) % ((int) 1e9+7);
    ans[2][2] = (c*f + d*h) % ((int) 1e9+7);

    return ans;
}

int fastFib(int x) {
    //x--;
    vector2d multi = {
        {0, 0, 0},
        {0, p, 1},
        {0, o, 0},
    };
    vector2d sum = {
        {0, 0, 0},
        {0, m, n},
        {0, 0, 0},
    };
    while (x > 0) {
        if (x & 1) {
            sum = matrixMultiply(sum, multi);
        }
        multi = matrixMultiply(multi, multi);
        x >>= 1;
    }
    return sum[1][1];
}


void solve() {

    /*int n = 1, m = 1, o = 5, p = 10, q = 5;
    vector2d multi = {
        {0, 0, 0},
        {0, p, 1},
        {0, o, 0},
    };
    vector2d sum = {
        {0, 0, 0},
        {0, m, n},
        {0, 0, 0},
    };
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j <= 2; j++) {
            for (int k = 1; k <= 2; k++) {
                cout << sum[j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
        sum = matrixMultiply(sum, multi);
    }*/
    cin >> n >> m >> o >> p >> q;
    cout << fastFib(q-2) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

