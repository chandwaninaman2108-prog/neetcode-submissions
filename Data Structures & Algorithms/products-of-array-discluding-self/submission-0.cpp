class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> before(n,1),after(n,1);
        int prod1=1,prod2=1;
        for(int i=0;i<n;i++){
            before[i]=prod1;
            after[n-1-i]=prod2;
            prod1*=nums[i];
            prod2*=nums[n-i-1];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=before[i]*after[i];
        }
        return ans;
    }
};