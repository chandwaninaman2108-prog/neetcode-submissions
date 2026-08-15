class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Solving using 1D array simulation 1D=n*i+j   i=1D/n, j=1D%n;
        int n=matrix[0].size(),m=matrix.size();
        int st=0,end=m*n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(matrix[mid/n][mid%n]==target) return true;
            else{
                if(matrix[mid/n][mid%n]>target){end=mid-1;}
                else{st=mid+1;}
            }
        }
        return false;
        
        
    }
};
