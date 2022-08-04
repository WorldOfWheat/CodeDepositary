#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    while (cin >> n >> m) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            nums.push_back(a);
        }
        //
        queue<int> windows;
        multiset<int> ms;
        multiset<int> ms2;
        int left = 0;
        int right = 0;
        for (int i = 0; i < m; i++) {
            int num = nums[i];
            if (i==0) {
                ms.insert(num);
                left += num;
            }
            else {
                auto it = ms.end();
                it--;
                if (num > *it) {
                    ms2.insert(num);
                    right += num;
                } else {
                    ms.insert(num);
                    left += num;
                }
                if (ms.size() > ms2.size()) {
                    auto it2 = ms.end();
                    it2--;
                    ms2.insert(*it2);
                    ms.erase(ms.find(*it2));
                    right += *it2;
                    left -= *it2;
                }
                if (ms.size() < ms2.size()) {
                    auto it2 = ms2.begin();
                    ms.insert(*it2);
                    ms2.erase(ms2.find(*it2));
                    left += *it2;
                    right -= *it2;
                }
            }
            windows.push(nums[i]);
        }
        for (int i = m; i <= n; i++) {
            auto it = ms.end();
            it--;
            int mid = 0;
            if (ms.size() == ms2.size())
                mid = (*it + *ms2.begin()) / 2;
            else
                mid = (ms.size() > ms2.size()) ? *it : *ms2.begin();
            int sum = 0;
            sum += ms.size()*mid - left;
            sum += right - ms2.size()*mid;
            cout << abs(sum) << " ";
 
            int f = windows.front();
            auto it3 = ms.find(f);
            if (it3 != ms.end())
                ms.erase(ms.find(f)), left -= f;
            else
                ms2.erase(ms2.find(f)), right -= f;
            windows.pop();
 
            int num = nums[i];
            windows.push(num);
            if (*ms2.begin() < num) {
                ms2.insert(num);
                right += num;
            } else {
                ms.insert(num);
                left += num;
            }
            if (ms.size() > ms2.size()) {
                auto it2 = ms.end();
                it2--;
                ms2.insert(*it2);
                ms.erase(ms.find(*it2));
                right += *it2;
                left -= *it2;
            }
            if (ms.size() < ms2.size()) {
                auto it2 = ms2.begin();
                ms.insert(*it2);
                ms2.erase(ms2.find(*it2));
                left += *it2;
                right -= *it2;
            }
        }
        //
        cout << endl;
    }
    return 0;
}
