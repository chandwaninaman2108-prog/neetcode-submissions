class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int st=0,end=n-1;
        while(st<end){
            while(!isalnum(s[st]) && st<end) st++;
            while(!isalnum(s[end])&& st<end) end--;
            if(st<end && tolower(s[st]) != tolower(s[end])) return false;
            st++; end--;
        }
        return true;
    }
};
