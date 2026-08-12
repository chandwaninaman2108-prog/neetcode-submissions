class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // character frequency count
        unordered_map<string,vector<string>> anagram;
        for(const string& str :strs){
            vector<int> count(26,0);
            for(char c : str){
                count[c-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+=to_string(count[i])+" ";
            }
            anagram[key].push_back(str);
        }
        vector<vector<string>> ans;
        // remeber the syntax for maps iteration using loops
        for(auto const& [key,val]: anagram){
            ans.push_back(val);
        }
        return ans;
    }
};