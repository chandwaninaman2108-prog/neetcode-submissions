class Solution {
public:
    int mincoins(vector<int>& coins,int x,vector<int>&dp){
        if(x==0) return 0;
        if(x<0) return INT_MAX/2;
        if(dp[x]!=-1) return dp[x];
        int ans=INT_MAX/2;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=x){
                int sub=mincoins(coins,x-coins[i],dp);
                ans=min(ans,sub+1);
            }
        }
        dp[x]=ans;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=mincoins(coins,amount,dp);
        return ans>=INT_MAX/2?-1:ans;
    }
};
