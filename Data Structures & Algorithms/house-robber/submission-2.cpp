class Solution {
public:
    int dp(vector<int>& nums,int n,vector<int>& robbed){
        if(n<=0) return 0;
        if(robbed[n]!=-1) return robbed[n];
        robbed[n]=max(dp(nums,n-2,robbed)+nums[n-1],dp(nums,n-1,robbed));
        return robbed[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> robbed(n+1,-1);
        return dp(nums,n,robbed);
    }
};
