class Solution {
public:
    bool isvalid(char c){
        if(c==' ') return false;
        int a=c;
        if(a<48||a>57&&a<65||a>90&&a<97||a>122) return false;
        return true;
    }
    char small(char a){
        int t=a;
        if(t>=65&&t<=90){char k= 'a'+a-'A'; return k;}
        return a;
    }
    bool isPalindrome(string s) {
        int n=s.length();
        int st=0,end=n-1;
        while(st<end){
            if(!isvalid(s[st])){st++;}
            else if(!isvalid(s[end])){end--;}
            else if(st<end && isvalid(s[st])){
                if(small(s[st])!=small(s[end])){return false;}
                st++;end--;
            }
        }
        return true;
    }
};
