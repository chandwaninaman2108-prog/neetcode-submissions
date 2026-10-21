class Solution {
public:
    void back(int n,string& s,int rc,int lc,vector<string>& ans){
        if(s.length()==2*n){ans.push_back(s); return;}
        if(lc<n){s+="("; back(n,s,rc,lc+1,ans); s.pop_back();}
        if(rc<lc){s+=")";back(n,s,rc+1,lc,ans); s.pop_back();}
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        int rc=0,lc=0;
        back(n,s,rc,lc,ans);
        return ans;
    }
};
