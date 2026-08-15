class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int st=0,end=m*n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(matrix[mid/n][mid%n]==target){
                return true;
            }
            else{
                if(matrix[mid/n][mid%n]<target){st=mid+1;}
                else{end=mid-1;}
            }
        }
        return false;
    }
};
