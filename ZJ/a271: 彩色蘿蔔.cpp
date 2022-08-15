#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define ln "\n"
#define sp " "

using namespace std;

int n;

class carrot {
    public:
        carrot(int x, int y, int z, int w, int n, int m) {
            red = x;
            white = y;
            yellow = z;
            black = w;
            poison = n;
            sum = m;
        }
        bool update(int x) {
            sum -= sum_poison;
            if (sum <= 0) {
                return true;
            }
            switch (x) {
                case 1: {
                    sum += red;
                    break;
                }
                case 2: {
                    sum += white;
                    break;
                }
                case 3: {
                    sum -= yellow;
                    break;
                }
                case 4: {
                    sum -= black;
                    sum_poison += poison;
                    break;
                }
            }
            return (sum <= 0);
        }
        int getSum() {
            return sum;
        }
    private:
        int red;
        int white;
        int yellow;
        int black;
        int poison;
        int sum_poison = 0;
        int sum = 0;
};

vector<int> input() {

    string str;
    getline(cin, str);

    stringstream ss(str);
    string str2;
    vector<int> result;

    while (getline(ss, str2, ' ') ) {
        result.push_back(atoi(str2.c_str()));
    }
    return result;
}

void solve() {

    vector<int> in = input();

    carrot ca(in[0], in[1], in[2], in[3], in[4], in[5]);
    in = input();
    if (in.empty()) {
        cout << (ca.getSum()) << "g" << ln;
        return;
    }
    for (auto a : in) {
        if ( ca.update(a) ) {
            cout << "bye~Rabbit" << ln;
            return;
        }
    }
    cout << (ca.getSum()) << "g" << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = input()[0];
    while (t--) solve();

    return 0;
}
