class Solution {
public:
    bool issafe(vector<string>& board,int row,int col,int n){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){return false;}
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){return false;}
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){return false;}
        }
        return true;
    }
    void backtrack(vector<string>& board,int row,vector<vector<string>>& ans){
        int n=board.size();
        if(row==n){ans.push_back(board); return;}
        for(int j=0;j<n;j++){
            if(issafe(board,row,j,n)){
                board[row][j]='Q';
                backtrack(board,row+1,ans);
                board[row][j]='.';
            }
        }
    
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>>ans;
        backtrack(board,0,ans);
        return ans;
    }
};
