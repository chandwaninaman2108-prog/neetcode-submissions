class Solution {
public:
    int dp(vector<int>& cost,int n,vector<int>& tcost){
        if(n<=1) return 0;
        if(tcost[n]!=-1) return tcost[n];
        tcost[n]=min(dp(cost,n-1,tcost)+cost[n-1],dp(cost,n-2,tcost)+cost[n-2]);
        return tcost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>tcost(n+1,-1);
        return dp(cost,n,tcost);
    }
};
