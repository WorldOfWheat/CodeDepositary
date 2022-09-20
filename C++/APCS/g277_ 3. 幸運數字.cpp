#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define pal pair<int, int>

using namespace std;

bool cmp(pal x, pal y) {return x.first < y.first;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> nums;
    priority_queue<pal, vector<pal>, greater<pal>> sorted;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
        sorted.push(make_pair(a, i));
    }
    long long sum[nums.size()] = {0};
    sum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        sum[i] = sum[i-1] + nums[i];
    }

    int l = 0;
    int r = nums.size() -1;
    while (l != r) {
        int a = 0;
        int minimum = 0;
        while (true) {
            minimum = sorted.top().second;
            if (sorted.top().second >= l && sorted.top().second <= r) break;
            sorted.pop();
        }
        long long sum_l = minimum - 1 >= 0 ? sum[minimum-1] - sum[l] : 0;
        long long sum_r = minimum + 1 < n ? sum[r] - sum[minimum+1] : 0;
        if (sum_l >= sum_r) {
            r = minimum -1;
        } else {
            l = minimum + 1;
        }
    }
    cout << nums[l] << endl;

    return 0;
}
