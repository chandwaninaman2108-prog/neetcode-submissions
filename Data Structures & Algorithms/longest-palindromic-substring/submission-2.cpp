class Solution {
public:
    bool solve(string &s,int i,int j,vector<vector<int>>& dp){
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            dp[i][j]=solve(s,i+1,j-1,dp);
        }
        else{dp[i][j]=0;}
        return dp[i][j];
    }
    string longestPalindrome(string s) {
        int n=s.length(),maxlen=INT_MIN,startingindex=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(solve(s,i,j,dp)){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        startingindex=i;
                    }
                }
            }
        }
        return s.substr(startingindex,maxlen);
    }
};
