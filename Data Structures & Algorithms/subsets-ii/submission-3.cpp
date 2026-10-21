class Solution {
public:
    void backtrack(vector<int>& nums,int idx,vector<int>& curr, vector<vector<int>>& ans){
        if(idx==nums.size()){ans.push_back(curr); return;}
        curr.push_back(nums[idx]);
        backtrack(nums,idx+1,curr,ans);
        curr.pop_back();
        int next=idx+1;
        while(next<nums.size() && nums[next]==nums[idx]){next++;}
        backtrack(nums,next,curr,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(nums,0,curr,ans);
        return ans;
    }
};
