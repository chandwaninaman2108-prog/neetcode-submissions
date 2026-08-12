class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> c;
        unordered_map<char,char> m={{')','('},{'}','{'},{']','['}};
        for(int i=0;i<n;i++){
            if(m.find(s[i])!=m.end()){
                if(c.empty() || m[s[i]]!=c.top()){
                    return false;
                }
                c.pop();
            }
            else{
                c.push(s[i]);
            }
        }
        return c.empty();
        }
};
