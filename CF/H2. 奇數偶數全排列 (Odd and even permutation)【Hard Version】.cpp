#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;
__attribute__((optimize("-O3")))

int f(int x[3]) {
    int sum = 0;
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++) {
        if (x[i] & 1) a++;
        else b++;
    }
    if (a==2) sum += 1;
    if (b==2) sum += 2;
    if (a == 3 || b == 3) sum += 5;
    
    for (int i = 1; i < 3; i++) {
        if ((x[i] & 1) == (x[i-1] & 1)) sum+=5;
    }
    if (x[0] + x[2] > x[1]) sum += 5;
    
    if (x[0] + x[1] > x[2] && x[0] + x[2] > x[1] && x[1] + x[2] > x[0]) sum += 7;
    return sum;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int nums[3];
    for (int i = 0; i < 3; i++) {
        cin >> nums[i];
    }
    int maxi = 0;
    do {
        maxi = max(maxi, f(nums) );
    } while (next_permutation(nums, nums+3));
    cout << maxi << endl;

    return 0;
}
