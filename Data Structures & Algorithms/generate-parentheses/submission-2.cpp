class Solution {
public:
    void backtrack(int n,string& s,int rc,int lc,vector<string>& ans){
        if(s.length()==2*n){ans.push_back(s); return;}
        if(lc<n){s+="(";backtrack(n,s,rc,lc+1,ans);s.pop_back();}
        if(lc>rc){s+=")"; backtrack(n,s,rc+1,lc,ans);s.pop_back();}
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string> ans;
        int rc=0,lc=0;
        backtrack(n,s,rc,lc,ans);
        return ans;
    }
};
