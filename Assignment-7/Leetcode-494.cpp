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
