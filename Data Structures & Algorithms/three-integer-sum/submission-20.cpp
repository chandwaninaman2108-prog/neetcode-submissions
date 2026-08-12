class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){continue;}
            int target=nums[i];
            int st=i+1,end=n-1;
            while(st<end){
                int sum=target+nums[st]+nums[end];
                if(sum==0){
                    triplets.push_back({target,nums[st],nums[end]});
                    st++;end--;
                    while(st<end && nums[st]==nums[st-1]){st++;}
                    while(st<end && nums[end]==nums[end+1]){end--;}
                }
                else if(sum<0){st++;}
                else{end--;}
            }
        }
        return triplets;
    }
};