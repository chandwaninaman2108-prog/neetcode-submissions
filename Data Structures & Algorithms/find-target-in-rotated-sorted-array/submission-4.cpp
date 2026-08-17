class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0,end=nums.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){return mid;}
            if(target<nums[mid]){
                if((nums[mid]>nums[st] && target>=nums[st]) ||(nums[mid]<nums[st] && target<nums[st])) end=mid-1;// Since I am using st as a refernce for comparison so using >= here in end modifying command is important.
                else{st=mid+1;}
            }
            else{
                if((nums[mid]<nums[end] && target<=nums[end]) || (nums[mid]>nums[end] && target>nums[end])) st=mid+1;
                else{end=mid-1;}
            }
        }
        return -1;
    }
};
