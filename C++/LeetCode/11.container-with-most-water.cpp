class Solution {
public:
    int maxArea(vector<int>& height) {
        int ptrL = 0;
        int ptrR = height.size() - 1;

        int ans = -1;
        while (ptrL < ptrR) {
            int k = min(height[ptrL], height[ptrR]) * (ptrR - ptrL);
            ans = max(ans, k);

            if (height[ptrL] < height[ptrR]) {
                ptrL++;
            }
            else {
                ptrR--;
            }
        }    

        return ans;
    }
};
