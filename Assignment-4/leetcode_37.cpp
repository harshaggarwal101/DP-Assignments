class Solution {
public:
    bool solved=false;
    bool isSafe(int row,int col,int dig,vector<vector<char>>& board){
        for(int j=0;j<9;j++){
            if(board[row][j]==dig) return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==dig) return false;
        }
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == dig)
                    return false;
            }
        }
        return true;
    }

    void solve(vector<vector<char>>& board){
        if(solved) return;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char dig='1';dig<='9';dig++){
                        if(isSafe(i,j,dig,board)){
                            board[i][j]=dig;
                            solve(board);
                            if(solved) return;
                            board[i][j]='.';
                        }
                    }
                    return;
                }
            }
        }
        solved=true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};