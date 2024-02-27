#include <bits/stdc++.h>

using namespace std;

string str, str2;
set<int> different;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str >> str2;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != str2[i]) {
            different.insert(i);
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int left, right;
        cin >> left >> right;
        left--, right--;
        auto findResult = different.lower_bound(left);
        if (findResult == different.end() || *findResult > right) {
            cout << "Really?!" << '\n';
            continue;
        }
        cout << "I am so weak." << '\n';
    }
}

