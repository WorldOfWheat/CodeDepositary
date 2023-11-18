class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ve(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), ve.begin());

        double ans = 0;
        int mid = ve.size() / 2;
        if (ve.size() % 2) {
            ans = ve[mid];     
        }
        else {
            int mid = ve.size() / 2;
            ans = (ve[mid-1] + ve[mid]) / 2.0;
        }

        return ans;
    }
};
