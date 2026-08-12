class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        if(s.length()!=t.length()) return false;
        for(char c:s){
            m[c]++;
        }
        for(char k:t){
            if(m[k]==0){
                return false;
            }
            m[k]--;
        }
        return true;
    }
};
