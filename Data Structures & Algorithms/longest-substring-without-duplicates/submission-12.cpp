class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==1){return 1;}
        int lp=0,rp=0,maxlen=0;
        unordered_set<char> u;
        while(lp<=rp && rp<n){
            
             while (u.find(s[rp]) != u.end()) {
    u.erase(s[lp]); 
    lp++;
}

// 2. Now the window is definitely valid, so add the new character
u.insert(s[rp]);

// 3. Calculate the length (Right index - Left index + 1) and update maxlen
int len = rp - lp + 1;
maxlen = max(maxlen, len);

// 4. Expand the window to the right for the next iteration
rp++;
        }
        return maxlen;
    }
};
