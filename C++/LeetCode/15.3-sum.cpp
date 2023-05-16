class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            int ptrL = i + 1;
            int ptrR = nums.size() - 1;

            while (ptrL < ptrR) {
                int sum = nums[i] + nums[ptrL] + nums[ptrR];

                if (sum > 0) {
                    ptrR--;
                }
                else if (sum < 0) {
                    ptrL++;
                }
                else {
                    vector<int> temp(3);
                    
                    temp[0] = nums[i];
                    temp[1] = nums[ptrL];
                    temp[2] = nums[ptrR];
                    ans.insert(temp);

                    ptrL++; 
                    ptrR--;
                }
            } 
        } 

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
