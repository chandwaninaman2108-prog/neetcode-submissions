class Solution {
public:
    void longincsub(vector<int>& nums, vector<int>& inc){int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                inc[i]=max(inc[j]+1,inc[i]);}
            }
        }
    }
    int lengthOfLIS(vector<int>& nums) {int n=nums.size();
        vector<int>dp(n,1);
        int maxlen=INT_MIN;
        longincsub(nums,dp);
        for(int i=0;i<n;i++){
            maxlen=max(maxlen,dp[i]);
        }
        return maxlen;
    }
};
