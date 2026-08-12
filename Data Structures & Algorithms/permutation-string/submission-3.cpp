class Solution {
public:
    string charctkey(unordered_map<char,int>& m){
        string key="";
        for(int i=97;i<=122;i++){
            char a=i;
            key+= to_string(m[a])+"#";
        }
        return key;

    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        int k=s1.length()-1;
        int l=0,r=0;
        vector<int> vs1(26,0),vs2(26,0);
        for(int i=0;i<=k;i++){
            int j= s1[i]-'a';
            vs1[j]++;
        }
        while(l<=r && r<s2.length()){
            vs2[s2[r]-'a']++;
            if(r==l+k){
                if(vs2==vs1) return true;
                vs2[s2[l]-'a']--;
                l++;
            }
            r++;
        }
        return false;
    }
};
