class Solution {
public:
    void longincsub(vector<int>& nums,vector<int>& dp){
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
    }
    int lengthOfLIS(vector<int>& nums) {int n=nums.size();
        vector<int>dp(n,1);
        longincsub(nums,dp);
        int maxlen=1;
        for(int i=0;i<n;i++){
            maxlen=max(maxlen,dp[i]);
        }
        return maxlen;
    }
};
