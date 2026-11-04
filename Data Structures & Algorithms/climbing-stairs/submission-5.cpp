class Solution {
public:
    int dp(int n,vector<int>& cs){
        if(n==0 || n==1) return 1;
        if(cs[n]!=-1) return cs[n];
        cs[n]=dp(n-1,cs)+dp(n-2,cs);
        return cs[n];
    }
    int climbStairs(int n) {
        vector<int> cs(46,-1);
        return dp(n,cs);
    }
};
