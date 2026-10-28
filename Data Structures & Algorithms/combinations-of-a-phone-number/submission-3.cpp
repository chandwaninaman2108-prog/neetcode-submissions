class Solution {
public:
    void backtrack(string& dig,string& s,unordered_map<char,string>& m,vector<string>& ans){
        if(s.size()==dig.size()){ans.push_back(s); return;}
        char currdig=dig[s.size()];
        string letters=m[currdig];
        for(char c:letters){
            string a=s;
            s+=c;
            backtrack(dig,s,m,ans);
            s=a;
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> m={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        if(digits==""){return {};}
        string s="";
        vector<string>ans;
        backtrack(digits,s,m,ans);
        return ans;
    }
};
