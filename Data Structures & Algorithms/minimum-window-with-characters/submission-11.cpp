class Solution {
public:
    bool vecfreqcomp(vector<int>& v1, vector<int>& v2){
        for(int i=0;i<128;i++){
            if(v1[i]>v2[i]){return false;}
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> vs1(128,0),vs2(128,0);
        for(char c:t){
            vs1[c]++;
        }
        int r=0,l=0,minlen=INT_MAX,minstart=0,n=s.length();
        while(l<=r && r<n){
            vs2[s[r]]++;
           if(vecfreqcomp(vs1,vs2)){
                int len=r-l+1;
                if(len<minlen){minlen=len; minstart=l;}
                vs2[s[l]]--;vs2[s[r]]--;
                l++;
                r--;
            }
            r++;
        }
        return minlen==INT_MAX? "": s.substr(minstart,minlen);
    }
};
