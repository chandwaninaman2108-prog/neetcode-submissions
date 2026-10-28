class Solution {
public:
    bool ispalin(string s){
        int n=s.length();
        int st=0,end=n-1;
        while(st<end){
            if(s[st]!=s[end]) return false;
            st++;
            end--;
        }
        return true;
    }
    void backtrack(int idx,string s,vector<string>& path,vector<vector<string>>& ans){
        if(idx==s.length()){
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(ispalin(s.substr(idx,i-idx+1))){
                path.push_back(s.substr(idx,i-idx+1));
                backtrack(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>>ans;
        backtrack(0,s,path,ans);
        return ans;
    }
};
