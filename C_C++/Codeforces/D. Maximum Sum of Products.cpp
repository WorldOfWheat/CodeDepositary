#include <bits/stdc++.h>
#define int long long
#define pa pair<int, int>
#define tp tuple<int, int, int>
#define db(x) cout << x << " "

using namespace std;
__attribute__((optimize("-O3")))

int n;
int arr[(int)5000+1];
int temp_arr[(int)5000+1];
int arr2[(int)5000+1];
int ps[(int)50002];
int maxi;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr2[i];
    }
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i-1] + arr[i]*arr2[i];
    }
    maxi = ps[n];
    for (int i = 2; i <= n; i++) {
        copy(arr, arr+n+1, temp_arr);
        int sum = 0;
        for (int j = 1; j <= i-1 && i+j <= n; j++) {
            swap(temp_arr[abs(i-j)], temp_arr[i+j]);

            if (j==1) sum += temp_arr[i+j-1]*arr2[i+j-1];
            sum += temp_arr[i-j]*arr2[i-j];
            sum += temp_arr[i+j]*arr2[i+j];

            maxi = max(maxi, sum + ps[i-j-1]-ps[0] + ps[n]-ps[i+j]);
        }
        sum = 0;
        copy(arr, arr+n+1, temp_arr);
        for (int j = 1; j <= i-1 && i+j-1 <= n; j++) {
            swap(temp_arr[abs(i-j)], temp_arr[i+j-1]);

            sum += temp_arr[abs(i-j)]*arr2[abs(i-j)];
            sum += temp_arr[i+j-1]*arr2[i+j-1];

            maxi = max(maxi, sum + ps[i-j-1]-ps[0] + ps[n]-ps[i+j-1]);
        }
    }
    cout << maxi << endl;

    return 0;
}
