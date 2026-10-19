
class Solution {
public:
    void backtrack(vector<int>& nums, int idx,
                   vector<int>& curr,
                   vector<vector<int>>& ans) {

        if (idx == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Include nums[idx]
        curr.push_back(nums[idx]);
        backtrack(nums, idx + 1, curr, ans);

        // Undo the choice
        curr.pop_back();

        // Exclude nums[idx]
        backtrack(nums, idx + 1, curr, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        backtrack(nums, 0, curr, ans);
        return ans;
    }
};
