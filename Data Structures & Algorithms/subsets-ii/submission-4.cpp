class Solution {
public:
    void back(vector<int>& nums,int idx, vector<int>& curr,vector<vector<int>>& ans){
        if(idx==nums.size()){ans.push_back(curr); return;}
        curr.push_back(nums[idx]);
        back(nums,idx+1,curr,ans);
        curr.pop_back();
        int next=idx+1;
        while(next<nums.size() && nums[next]==nums[idx]){next++;}
        back(nums,next,curr,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        vector<vector<int>>ans;
        back(nums,0,curr,ans);
        return ans;
    }
};
