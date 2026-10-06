class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int ct=1;
        while(ct<k){
            ct++;
            pq.pop();
        }
        return pq.top();
    }
};
