#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;

int binarySearch2(int target, int left, int right) {
    if (target < arr[left]) {
        return left;
    }

    int result = 0;
    for (int i = (right - left - 1) >> 1; i > 0; i >>= 1) {
        while (result + i < right && target >= arr[result + i]) {
            result += i;
        }
    }

    return result + 1;
}

int binarySearch(int target, int left, int right) {
    if (target <= arr[left]) {
        return left;
    }

    int result = 0;
    for (int i = (right - left - 1) >> 1; i > 0; i >>= 1) {
        while (result + i < right && target > arr[result + i]) {
            result += i;
        }
    }

    return result + 1;
}

void solve() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int in;
        cin >> in;
        cout << (binarySearch2(in, 0, n) - binarySearch(in, 0, n)) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
