class Solution {
public:
    void backtracking(vector<int>&nums,int idx,int remaining,vector<int>&curr,vector<vector<int>>& ans){
        if(remaining==0){ans.push_back(curr); return;}
        if(remaining<0){return;}
        if(idx==nums.size()) return;
        curr.push_back(nums[idx]);
        backtracking(nums,idx+1,remaining-nums[idx],curr,ans);
        curr.pop_back();
        int next=idx+1;
        while(next<nums.size() && nums[next]==nums[idx]){next++;}
        backtracking(nums,next,remaining,curr,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        vector<vector<int>>ans;
        backtracking(candidates,0,target,curr,ans);
        return ans;
    }
};
