class Solution {
public:
    int maxArea(vector<int>& heights) {
        //When will left++ and right -- take place is the real problem.
        int left=0,right=heights.size()-1;
        int maxarea=0;
        while(left<right){
            int area=(right-left)*min(heights[right],heights[left]);
            maxarea=max(area,maxarea);
            int diff=heights[right]-heights[left];
            diff<0 ? right-- : left++;
        }
        return maxarea;
    }
};
