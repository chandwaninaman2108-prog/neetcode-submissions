class Solution {
public:
    int maxcharcount(unordered_map<char,int>& m){
        int maxcount=0;
        for(int i=65;i<=90;i++){
            char a=i;
            if(m.find(a)!=m.end()){maxcount=max(maxcount,m[a]);}
        }
        return maxcount;
    }
    int characterReplacement(string s, int k) {
     int n=s.length();
     int l=0,r=0;
     unordered_map<char,int> m;// Hashing is required.
     int maxlen=0;
    while(l<=r && r<n){
        m[s[r]]++;
        int len=r-l+1;
        if(len-maxcharcount(m)<=k){maxlen=max(len,maxlen);r++;}
        else{ m[s[l]]--;m[s[r]]--; l++;}
    }
    return maxlen;
    }
};
