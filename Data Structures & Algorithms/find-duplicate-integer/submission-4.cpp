class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // forming a cyclic linked list and then finding a cycle.
        // Cycle can be found using slow and fast pointer approach.
        // Floyd's implementation
        int slow=nums[0];
        int fast=nums[0];
        do{slow=nums[slow]; fast=nums[nums[fast]];}while(slow!=fast);
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
