class Solution {
public:
    int dp(vector<int>& nums,int n,int st,vector<int>& robbed){
        if(st>n){return 0;}
        if(robbed[n]!=-1) return robbed[n];
        robbed[n]=max(nums[n]+dp(nums,n-2,st,robbed),dp(nums,n-1,st,robbed));
        return robbed[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> robbed(n,-1),robbed2(n,-1);
        if(n==1) return nums[0];
        return max(dp(nums,n-1,1,robbed),dp(nums,n-2,0,robbed2));
    }
};
