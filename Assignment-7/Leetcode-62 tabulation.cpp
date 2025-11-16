class Solution {
public:

    int solve(int row,int col,vector<vector<int>> &memo){
        memo[0][0]=1;
        for(int i=1;i<=row;i++){
            memo[i][0]=1;
        }
        for(int j=0;j<=col;j++){
            memo[0][j]=1;
        }
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                int a=memo[i-1][j];
                int b=memo[i][j-1];
                memo[i][j]=a+b;
            }
        }
        return memo[row][col];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return solve(m-1,n-1,memo);
    }
};
