class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int st=0,end=n-1,mid=0;
        while(st<end){
            mid=st+(end-st)/2;
            if(nums[mid]>nums[end]){st=mid+1;}
            else{end=mid;}
        }
        return nums[st];// when after execution of loop st==end, mid would be at some other position which is not the correct ans.
    }
};
