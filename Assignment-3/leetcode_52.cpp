class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board,int n){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q') return false;
        }
        for(int i=row-1, j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row-1, j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }

    void func(int row,int n,vector<string> &board,int &ans){
        if(row==n){
            ans++;
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                func(row+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int ans=0;
        func(0, n, board,ans);
        return ans;

    }
};