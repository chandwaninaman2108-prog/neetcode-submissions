class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        int n=s.length();
        if(n%2==1){return false;}
        unordered_map<char,char> m={{')','('},{'}','{'},{']','['}};
        for(int i=0;i<n;i++){
          if(m.find(s[i])!=m.end()){
            if(c.empty()||c.top()!=m[s[i]]){return false;}
            c.pop();
          }
          else{c.push(s[i]);}
        }
        return c.empty();

    }
};
