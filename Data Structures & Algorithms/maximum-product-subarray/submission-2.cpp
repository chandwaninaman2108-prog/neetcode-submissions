class Solution {
public:
    int prodmax(vector<int>& nums,vector<int>& mindp,vector<int>& maxdp){
        int ans=nums[0];
        maxdp[0]=nums[0];
        mindp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int curr=nums[i];
            maxdp[i]=max({curr,curr*maxdp[i-1],curr*mindp[i-1]});
            mindp[i]=min({curr,curr*maxdp[i-1],curr*mindp[i-1]});
            ans=max(ans,maxdp[i]);
        }
        return ans;
    }
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>maxdp(n);
        vector<int>mindp(n);
        return prodmax(nums,mindp,maxdp);
    }
};
