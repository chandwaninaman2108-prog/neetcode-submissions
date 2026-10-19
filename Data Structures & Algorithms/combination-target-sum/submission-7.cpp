class Solution {
public:
    void backtrack(vector<int>& nums,int idx,int remaining, vector<int>& curr, vector<vector<int>>& ans){
        if(remaining==0){ans.push_back(curr); return;}
        if(remaining<0) return;
        if(idx==nums.size()) return;
        curr.push_back(nums[idx]);
        backtrack(nums,idx,remaining-nums[idx],curr,ans);
        curr.pop_back();
        backtrack(nums,idx+1,remaining,curr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(nums,0,target,curr,ans);
        return ans;
    }
};
