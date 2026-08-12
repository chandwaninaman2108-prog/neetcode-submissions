class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9),coloumns(9),boxes(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char num=board[i][j];
                if(num=='.') continue;
                int box=(i/3)*3+(j/3);
                if(rows[i].count(num)||coloumns[j].count(num)||boxes[box].count(num)){
                    return false;
                }
                rows[i].insert(num);
                coloumns[j].insert(num);
                boxes[box].insert(num);
            }
        }
           return true;
    }
 
};
