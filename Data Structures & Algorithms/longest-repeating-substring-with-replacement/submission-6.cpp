class Solution {
public:
    int maxcharcount(unordered_map<char,int>& m){
        int maxcount=0;
        for(int i=65;i<=90;i++){
            char a=i;
            maxcount=max(m[a],maxcount);
        }
        return maxcount;
    }
    int characterReplacement(string s, int k) {
        int n=s.length();
        int l=0,r=0,maxlen=0;
        unordered_map<char,int> m;
        while(l<=r && r<n){
            m[s[r]]++;
            int len=r-l+1;
            if(len-maxcharcount(m)<=k){maxlen=max(maxlen,len); r++;} 
            else{m[s[l]]--;m[s[r]]--; l++;}
        }
        return maxlen;
    }
};
