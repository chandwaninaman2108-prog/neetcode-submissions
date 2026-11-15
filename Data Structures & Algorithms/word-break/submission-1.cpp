class Solution {
public:
    bool splitstr(string &s,vector<string>& wordDict,vector<bool>&dp){
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        for(int i=1;i<=s.length();i++){
            for(int j=0;j<i;j++){
                if(dp[j] && wordset.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.length()+1,false);
        dp[0]=true;
        return splitstr(s,wordDict,dp);
    }
};
