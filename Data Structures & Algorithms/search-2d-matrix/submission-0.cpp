class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),idx=0;
        for(int i=0;i<m;i++){
            if(target>=matrix[i][0] && target<=matrix[i][n-1]){
                idx=i;
                break;
            }
        }
        //Now we will be using binary search 
        int st=0,end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(matrix[idx][mid]==target) return true;
            else{
                if(matrix[idx][mid]>target){end=mid-1;}
                else{st=mid+1;}
            }
        }
        return false;
        
        
    }
};
