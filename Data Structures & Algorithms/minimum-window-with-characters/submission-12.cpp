class Solution {
public:
    bool vecfreqcount(vector<int>& v1, vector<int>& v2){
        for(int i=0;i<128;i++){
            if(v1[i]>v2[i]){return false;}
        }
        return true;
    }
    string minWindow(string s, string t) {
        int l=0,r=0,minlen=INT_MAX,n=s.length(),minleft=0;
        vector<int> vs1(128,0),vs2(128,0);
        for(char c:t){
            vs1[c]++;
        }
        while(l<=r && r<n){
            vs2[s[r]]++;
            while(vecfreqcount(vs1,vs2)){
                int len=r-l+1;
                if(len<minlen){
                    minlen=len;
                    minleft=l;
                }
                vs2[s[l]]--;
                l++;
            }
            r++;
        }
        return minlen==INT_MAX? "": s.substr(minleft,minlen);
    }
};
