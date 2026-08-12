class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int lp=0,rp=0,maxlen=0;
        unordered_set<char> u;
        while(lp<=rp && rp<n){
            while(u.find(s[rp])!=u.end()){
                u.erase(s[lp]);
                lp++;
            }
            u.insert(s[rp]);
            int len=rp-lp+1;
            maxlen=max(maxlen,len);
            rp++;
        }
        return maxlen;

    }
};
