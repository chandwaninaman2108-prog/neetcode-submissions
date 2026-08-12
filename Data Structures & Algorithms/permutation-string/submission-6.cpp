class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0,r=0,k=s1.length()-1;
        vector<int> vs1(26,0),vs2(26,0);
        for(int i=0;i<=k;i++){
            int j=s1[i]-'a';
            vs1[j]++;
        }
        while(l<=r && r<s2.length()){
            vs2[s2[r]-'a']++;
            if(r==l+k){
                if(vs2==vs1) return true;
                vs2[s2[l]-'a']--;// forgot to reduce the left character freq to move/slide the window.
                l++;
            }
            r++;
        }
        return false;
    }
};
