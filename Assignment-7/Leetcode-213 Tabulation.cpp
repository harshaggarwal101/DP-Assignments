class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp, int base){
        dp[0] = nums[base];
        if (dp.size() > 1)
            dp[1] = max(nums[base], nums[base+1]);

        for (int k = 2; k < dp.size(); k++) {
            int pick = dp[k-2] + nums[base + k];
            int notpick = dp[k-1];
            dp[k] = max(pick, notpick);
        }
        return dp[dp.size()-1];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> dp1(nums.size()-1, -1);
        vector<int> dp2(nums.size()-1, -1);

        return max(
            solve(nums.size()-1, nums, dp1, 1),
            solve(nums.size()-2, nums, dp2, 0)
        );
    }
};
