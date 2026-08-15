class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> c;
        for(string& token:tokens){
            if(token=="+"||token=="-"||token=="*"||token=="/"){
                int a=c.top();
                c.pop();
                int b=c.top();
                c.pop();
                if(token=="+"){c.push(a+b);}
                else if(token=="-"){c.push(b-a);}
                else if(token=="*"){c.push(a*b);}
                else{c.push(b/a);}
            }
            else{c.push(stoi(token));}// stoi 
        }
        return c.top();
    }
};
