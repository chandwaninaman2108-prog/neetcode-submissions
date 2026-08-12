class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea=0,left=0,right=heights.size()-1;
        while(left<right){
            int area=(right-left)*min(heights[left],heights[right]);
            maxarea=max(area,maxarea);
            int diff=heights[right]-heights[left];
            diff>0 ? left++ : right--;// mistakenly wrote left-- & right++
        }
        return maxarea;
    }
};
