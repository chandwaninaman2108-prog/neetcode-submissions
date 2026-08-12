class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        
        for (int i = 0; i < n; i++) {
            // 1. Skip duplicates for our main pointer 'i'
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int target = nums[i];
            int st = i + 1, end = n - 1; // Fixed syntax error here (comma instead of semicolon)
            
            while (st < end) {
                int sum = nums[st] + nums[end];
                
                if (sum + target == 0) {
                    // C++ allows directly pushing an initializer list
                    triplets.push_back({target, nums[st], nums[end]});
                    st++; 
                    end--;
                    
                    // 2. Skip duplicates for 'st' ONLY after we found a match
                    while (st < end && nums[st] == nums[st - 1]) {
                        st++;
                    }
                    // 3. Skip duplicates for 'end' ONLY after we found a match
                    while (st < end && nums[end] == nums[end + 1]) {
                        end--;
                    }
                } 
                else if (sum + target < 0) {
                    st++;
                } 
                else {
                    end--;
                }
            }
        }
        
        return triplets; // Added missing return statement
    }
};