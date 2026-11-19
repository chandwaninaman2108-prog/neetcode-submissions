class Solution {
public:
    void partsubset(vector<int>& nums,vector<bool>& dp,int target){
        for(int num:nums){
            for(int i=target;i>=num;i--){
                dp[i]=dp[i]||dp[i-num];
            }
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        int target = sum/2;
        vector<bool> dp(target+1,false);
        dp[0]=true;
        partsubset(nums,dp,target);
        return dp[target];
    }
};
