class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(dp[row][col]!=-1) return dp[row][col];
        if(row==grid.size()-1 && col==grid[0].size()-1){
            if(grid[grid.size()-1][grid[0].size()-1]==1) return dp[row][col]=0;
            else return dp[row][col]=1;
        }
        if(row==grid.size()||col==grid[0].size()) return dp[row][col]=0;
        if(grid[row][col]==1) return dp[row][col]=0;
        int down=solve(row+1,col,grid,dp);
        int right=solve(row,col+1,grid,dp);
        return dp[row][col]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size()+1,vector<int>(vector<int>(obstacleGrid[0].size()+1,-1)));
        return solve(0,0,obstacleGrid,dp);
    }
};
