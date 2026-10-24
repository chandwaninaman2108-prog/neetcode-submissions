class Solution {
public:
    void backtrack(vector<vector<char>>& board,int i,int j,string& word, int idx, bool& yes){
        if(yes){return;}
        if(idx==word.size()){yes=true; return;}
        if(i>=board.size() || i<0){return;}
        if(j>=board[0].size()||j<0){return;}
        if(board[i][j]!=word[idx]){return;}
        char temp=board[i][j];
        board[i][j]='#';
        backtrack(board,i-1,j,word,idx+1,yes);
        backtrack(board,i,j-1,word,idx+1,yes);
        backtrack(board,i,j+1,word,idx+1,yes);
        backtrack(board,i+1,j,word,idx+1,yes);
        board[i][j]=temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool yes=false;
        int idx=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(yes){break; break;}
                backtrack(board,i,j,word,idx,yes);
            }
        }
        return yes;
    }
};
