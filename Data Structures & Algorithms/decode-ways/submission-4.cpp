class Solution {
public:
    /*Ways to decode[i]=waystodecode[i-1](if new single digit is valid)+waystodecode[i-2]*(if combined last two digits make a valid alphabet*/
    int decode(string &s,vector<int>& dp){int n=s.length();
        dp[0]=1;
        dp[1]=s[0]=='0'?0:1;
        for(int i=2;i<=n;i++){
            int comb=stoi(s.substr(i-2,2));
            int comb1=stoi(s.substr(i-1,1));
            if(comb1>=1){dp[i]+=dp[i-1];}
            if(comb<=26 && comb>=10){dp[i]+=dp[i-2];}
        }
        return dp[n];
    }
    int numDecodings(string s) {int n=s.length();
        vector<int> dp(n+1,0);
        return decode(s,dp);
    }
};
