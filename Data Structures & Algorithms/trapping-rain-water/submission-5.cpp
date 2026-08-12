class Solution {
public:
    int trap(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int left_max=0,right_max=0,water=0;
        while(left<right){
            if(nums[left]<=nums[right]){
                if(nums[left]>left_max){left_max=nums[left];}
                else{
                    water+=(left_max-nums[left]);
                }
                left++;
            }
            else{
                if(nums[right]>right_max){right_max=nums[right];}
                else{
                    water+=(right_max-nums[right]);
                }
                right--;
            }
        }
        return water;
    }
};
