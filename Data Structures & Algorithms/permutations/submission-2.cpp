class Solution {
public:
    void back(vector<int>& nums,vector<bool>& used,vector<int>& curr,vector<vector<int>>& ans){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            curr.push_back(nums[i]);
            used[i]=true;
            back(nums,used,curr,ans);
            curr.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>>ans;
        vector<bool>used(nums.size(),false);
        back(nums,used,curr,ans);
        return ans;
    }
};
