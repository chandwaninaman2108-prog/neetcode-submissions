class Solution {
public:
    int decode(string &s,vector<int>& dp){int n=s.length();
        dp[0]=1;
        dp[1]=s[0]=='0'?0:1;
        for(int i=2;i<=n;i++){
            int c1=stoi(s.substr(i-1,1));
            int c2=stoi(s.substr(i-2,2));
            if(c1){dp[i]+=dp[i-1];}
            if(c2>=10 && c2<=26){dp[i]+=dp[i-2];}
        }
        return dp[n];
    }
    int numDecodings(string s) {int n=s.length();
        vector<int> dp(n+1,0);
        return decode(s,dp);
    }
};
