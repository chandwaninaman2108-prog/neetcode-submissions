class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int length=0,maxlength=0;
        for(int i:s){
            if(s.find(i-1)==s.end()){
                length=0;
                while(s.find(i+length)!=s.end()){
                        length++;
                }
                maxlength=max(length,maxlength);
            }
        }
        return maxlength;
        
    }
};
