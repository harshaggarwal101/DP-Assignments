class Solution {
public:

    int solve(int r, int c, vector<vector<int>>& dungeon,vector<vector<int>>& dp) {
    int m = dungeon.size();
    int n = dungeon[0].size();

    if(dp[r][c]!=-1) return dp[r][c];
    //  Out of bounds
    if (r >= m || c >= n) return 1e9;
    
    //  Base case
    if (r == m-1 && c == n-1) {
        if (dungeon[r][c] >= 0) return dp[r][c]= 1;
        else return dp[r][c]=1 - dungeon[r][c];
    }

    //  Recursive calls
    int right = solve(r, c+1,dungeon,dp);
    int down  = solve(r+1, c,dungeon,dp);
    int needNext = min(right, down);

    int need = needNext - dungeon[r][c];
    if (need <= 0) need = 1;
    return dp[r][c]=need;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size()+1,vector<int>(dungeon[0].size()+1,-1));
        return solve(0,0,dungeon,dp);
    }
};
