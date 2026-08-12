class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1,water=0,left_max=0,right_max=0;
        while(left<right){
        if(height[left]<=height[right]){
            if(height[left]>left_max){left_max=height[left];}
            /*if left_max is getting modified in the code, this implies a right bar bigger than left_max 
            exists in the array.*/
            else{
                water+=(left_max-height[left]);
            }
            left++;
        }
        else{
            if(height[right]>right_max){right_max=height[right];}
            /*Same for right_max, if it gets modifies then that means a right_bar bigger than the array exists in the code.*/
            else{
                water+=right_max-height[right];
            }
            right--;
        }
        
    } return water;}
};
