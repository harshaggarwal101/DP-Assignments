class Solution {
public:

    int solve(vector<int>& nums,int target,int curr,int i,vector<vector<int>>& dp,int offset){
        if(i==nums.size()){
            return (curr==target?1:0);
        }
        if(dp[i][curr+offset]!=-1) return dp[i][curr+offset];
        int plus=solve(nums,target,curr+nums[i],i+1,dp,offset);
        int minus=solve(nums,target,curr-nums[i],i+1,dp,offset);
        return dp[i][curr+offset]= plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>  dp(nums.size()+1,vector<int>(2001,-1));
        return solve(nums,target,0,0,dp,1000);
    }
};

// Tabulation solution
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        
        int offset = 1000;
        int maxSum = 2000;

        vector<vector<int>> dp(n+1, vector<int>(maxSum + 1, 0));
        
        dp[0][0 + offset] = 1;

        for (int i = 1; i <= n; i++) {
            int val = nums[i-1];
            for (int sum = 0; sum <= maxSum; sum++) {

                int plus = 0, minus = 0;

                // coming from previous row: sum - val
                if (sum - val >= 0)
                    plus = dp[i-1][sum - val];

                if (sum + val <= maxSum)
                    minus = dp[i-1][sum + val];

                dp[i][sum] = plus + minus;
            }
        }

        int idx = target + offset;
        if (idx < 0 || idx > maxSum) return 0;
        
        return dp[n][idx];
    }
};
