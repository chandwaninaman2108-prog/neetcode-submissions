class Solution {
public:
    bool solve(string& s,int i,int j,vector<vector<int>>& dp){
        if(j<=i) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            dp[i][j]=solve(s,i+1,j-1,dp);
        }else{
            dp[i][j]=0;
        }
        return dp[i][j];
    }
    int countSubstrings(string s) {
        int n=s.length(),ct=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)){ct++;}
            }
        }
        return ct;
    }
};
